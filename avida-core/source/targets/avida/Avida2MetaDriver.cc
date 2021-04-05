/*
 *  Avida2MetaDriver.cc
 *  avida
 *
 *  Created by David on 12/11/05.
 *  Copyright 1999-2011 Michigan State University. All rights reserved.
 *  http://avida.devosoft.org/
 *
 *
 *  This file is part of Avida.
 *
 *  Avida is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 *
 *  Avida is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License along with Avida.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Authors: David M. Bryson <david@programerror.com>
 *
 */

#include "Avida2MetaDriver.h"

#include "avida/core/Context.h"
#include "avida/core/World.h"
#include "avida/systematics/Group.h"

#include "cAnalyze.h"
#include "cAvidaContext.h"
#include "cHardwareBase.h"
#include "cHardwareManager.h"
#include "cOrganism.h"
#include "cPopulation.h"
#include "cPopulationCell.h"
#include "cStats.h"
#include "cWorld.h"
#include "cEnvironment.h"
#include "cReactionProcess.h"
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace Avida;
using namespace std;


Avida2MetaDriver::Avida2MetaDriver(cWorld* world, World* new_world) : m_world(world), m_new_world(new_world), m_done(false)
{
  GlobalObjectManager::Register(this);
  world->SetDriver(this);
}

Avida2MetaDriver::~Avida2MetaDriver()
{
  GlobalObjectManager::Unregister(this);
  // delete m_world;
}

// MODIFIED: was void function
double Avida2MetaDriver::Run(int num_updates, FileSystem m_fs, bool save, int m_iworld)
{ 
  if (m_world->GetConfig().ANALYZE_MODE.Get() > 0) {
    cout << "In analyze mode!!" << endl;
    cAnalyze& analyze = m_world->GetAnalyze();
    analyze.RunFile(m_world->GetConfig().ANALYZE_FILE.Get());
    if (m_world->GetConfig().ANALYZE_MODE.Get() == 2) analyze.RunInteractive();
    return 0; // MODIFIED
  }
  

  cPopulation& population = m_world->GetPopulation();
  cStats& stats = m_world->GetStats();
  
  const double point_mut_prob = m_world->GetConfig().POINT_MUT_PROB.Get() +
                                m_world->GetConfig().POINT_INS_PROB.Get() +
                                m_world->GetConfig().POINT_DEL_PROB.Get() +
                                m_world->GetConfig().DIV_LGT_PROB.Get();
  
  void (cPopulation::*ActiveProcessStep)(cAvidaContext& ctx, double step_size, int cell_id) = &cPopulation::ProcessStep;
  if (m_world->GetConfig().SPECULATIVE.Get() &&
      m_world->GetConfig().THREAD_SLICING_METHOD.Get() != 1 && !m_world->GetConfig().IMPLICIT_REPRO_END.Get() && point_mut_prob == 0.0) {
    ActiveProcessStep = &cPopulation::ProcessStepSpeculative;
  }
  
  cAvidaContext& ctx = m_world->GetDefaultContext();
  Avida::Context new_ctx(this, &m_world->GetRandom());

  
  
  // MODIFIED
  int num_tasks = m_world->m_controller->m_num_tasks;
  int intervention_frequency = m_world->m_controller->m_intervention_frequency;
  double phi, old_phi=0;
  m_phi_0_sum = 0;
  if (save) m_fs.InitUpdateData(m_iworld, num_tasks);

  int u = 0;
  while (!m_done) {

    m_world->GetEvents(ctx);
    if(m_done == true) break;
    
    // Increment the Update.
    stats.IncCurrentUpdate();
    
    population.ProcessPreUpdate();

    // Handle all data collection for previous update.
    if (stats.GetUpdate() > 0) {
      // Tell the stats object to do update calculations and printing.
      stats.ProcessUpdate();
    }
    
    // Process the update.
    // query the world to calculate the exact size of this update:
    const int UD_size = m_world->CalculateUpdateSize();
    const double step_size = 1.0 / (double) UD_size;
    
    for (int i = 0; i < UD_size; i++) { // NOTE: Kanske OpenMP parallellisering här?
      if(population.GetNumOrganisms() == 0) {
        break;
      }
      (population.*ActiveProcessStep)(ctx, step_size, population.ScheduleOrganism());
    }
    
    // end of update stats...
    population.ProcessPostUpdate(ctx);
    
		m_world->ProcessPostUpdate(ctx);
        
    // No viewer; print out status for this update....
    if (m_world->GetVerbosity() > VERBOSE_SILENT) {
      cout.setf(ios::left);
      cout.setf(ios::showpoint);
      cout << "UD: " << setw(6) << stats.GetUpdate() << "  ";
      cout << "Gen: " << setw(9) << setprecision(7) << stats.SumGeneration().Average() << "  ";
      cout << "Fit (phi_i): " << setw(9) << setprecision(7) << stats.GetAveFitness() << "  ";
      cout << "Fit (Phi_0): " << stats.GetPhi0Fitness() << " "; // MODIFIED: added this line
      cout << "Orgs: " << setw(6) << population.GetNumOrganisms() << "  ";
      if (m_world->GetPopulation().GetNumDemes() > 1) cout << "Demes: " << setw(4) << stats.GetNumOccupiedDemes() << " ";
      if (m_world->GetVerbosity() == VERBOSE_ON || m_world->GetVerbosity() == VERBOSE_DETAILS) {
        cout << "Merit: " << setw(9) << setprecision(7) << stats.GetAveMerit() << "  ";
        cout << "Thrd: " << setw(6) << stats.GetNumThreads() << "  ";
        cout << "Para: " << stats.GetNumParasites() << "  ";
      }
      if (m_world->GetVerbosity() >= VERBOSE_DEBUG) {
        cout << "Spec: " << setw(6) << setprecision(4) << stats.GetAveSpeculative() << "  ";
        cout << "SWst: " << setw(6) << setprecision(4) << (((double)stats.GetSpeculativeWaste() / (double)m_world->CalculateUpdateSize()) * 100.0) << "%  ";
      }
      cout << endl;
    }
    
    // Get controller fitness
    m_phi_0_sum += stats.GetPhi0Fitness();
    if (stats.GetPhi0Fitness() < 0.0000000000001) return 0;

    // Controller interaction with avida
    if (u%intervention_frequency == 0 || u == 0)  {
      
      // Get avida state
      std::vector<double> performed_task_fraction = std::vector<double>(num_tasks, 0);
      for (size_t k=0; k<num_tasks; k++)
        performed_task_fraction[k] = (double) m_world->m_controller->m_task_performed_counter[k]/population.GetLiveOrgList().GetSize();
      phi = log10(stats.GetAveFitness()+1);
      double delta_phi = phi / (old_phi+0.01);
      old_phi = phi;


      // Apply controller strategy
      m_strategy = m_world->m_controller->EvaluateAvidaFas3(performed_task_fraction, (double)u/num_updates, delta_phi);
      for (size_t j=0; j<num_tasks; j++)
        m_world->GetEnvironment().vec_reactions[j]->SetValue(m_strategy[j]);
    }

    // MODIFIED
    std::vector<int> task_count = std::vector<int>(num_tasks, 0);
    for (int j=0;j<num_tasks;j++){
      task_count[j] = stats.GetTaskLastCount(j);
    }

    if (save)
      m_fs.SaveUpdateData(m_iworld, stats.GetUpdate(), stats.SumGeneration().Average(), stats.GetAveFitness(), stats.GetPhi0Fitness(), population.GetNumOrganisms(), task_count, num_tasks, m_strategy);


    // Do Point Mutations
    if (point_mut_prob > 0 ) {
      for (int i = 0; i < population.GetSize(); i++) {
        if (population.GetCell(i).IsOccupied()) {
          int num_mut = population.GetCell(i).GetOrganism()->GetHardware().PointMutate(ctx);
          population.GetCell(i).GetOrganism()->IncPointMutations(num_mut);
        }
      }
    }
    
    m_new_world->PerformUpdate(new_ctx, stats.GetUpdate());
    
    // Exit conditons...
    if((population.GetNumOrganisms()==0) && m_world->AllowsEarlyExit()) {
			m_done = true;
		}
    // MODIFIED
    u++;
    if (u == num_updates) m_done = true;

    
  }

  // MODIFIED
  return m_phi_0_sum;
}


void Avida2MetaDriver::Abort(Avida::AbortCondition condition)
{
  exit(condition);
}

void Avida2MetaDriver::StdIOFeedback::Error(const char* fmt, ...)
{
  printf("error: ");
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}

void Avida2MetaDriver::StdIOFeedback::Warning(const char* fmt, ...)
{
  printf("warning: ");
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}

void Avida2MetaDriver::StdIOFeedback::Notify(const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}

