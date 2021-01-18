/*
 *  AvidaMetaDriver.cc
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

#include "AvidaMetaDriver.h"

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
#include "cGod.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace Avida;
using namespace std;


AvidaMetaDriver::AvidaMetaDriver(cWorld* worlds[], World* new_worlds[], cGod* God) //: m_worlds(worlds), m_new_worlds(new_worlds), m_god(God), m_done(false)
{
  GlobalObjectManager::Register(this);
  m_god=God;
  for (int i=0; i<m_god->m_number_of_worlds;i++){
      cout << "Constructor Driver" << endl;
      m_worlds[i] = worlds[i];
      m_new_worlds[i] = new_worlds[i];
      worlds[i]->SetDriver(this); //This might be a problem. finsihing the driver
  }
  m_done=false;
  
}

AvidaMetaDriver::~AvidaMetaDriver()
{
  GlobalObjectManager::Unregister(this);
  delete m_worlds;
}


void AvidaMetaDriver::Run()
{
  /*
  if (m_world->GetConfig().ANALYZE_MODE.Get() > 0) {
    cout << "In analyze mode!!" << endl;
    cAnalyze& analyze = m_world->GetAnalyze();
    analyze.RunFile(m_world->GetConfig().ANALYZE_FILE.Get());
    if (m_world->GetConfig().ANALYZE_MODE.Get() == 2) analyze.RunInteractive();
    return;
  }*/
  /*
  cWorld* m_worlds[1];
  m_worlds[0] = m_world;
  Avida::World* new_worlds[1];
  new_worlds[0] = m_new_world;
  */
  int n_worlds = 2;//m_god->m_number_of_worlds;
  
  cPopulation* population[n_worlds];
  cStats* stats[n_worlds];
  for (int i =0; i<n_worlds; i++){
      population[i] = &m_worlds[i]->GetPopulation();
      stats[i] = &m_worlds[i]->GetStats();
  }
//   cPopulation* population[1];
//   population[0] = &m_worlds[0]->GetPopulation();
//   cStats* stats[1];
//   stats[0] = &m_worlds[0]->GetStats();
  
  const double point_mut_prob = m_worlds[0]->GetConfig().POINT_MUT_PROB.Get() +
                                m_worlds[0]->GetConfig().POINT_INS_PROB.Get() +
                                m_worlds[0]->GetConfig().POINT_DEL_PROB.Get() +
                                m_worlds[0]->GetConfig().DIV_LGT_PROB.Get();
  
  void (cPopulation::*ActiveProcessStep)(cAvidaContext& ctx, double step_size, int cell_id) = &cPopulation::ProcessStep;
  /*
  if (m_worlds[0]->GetConfig().SPECULATIVE.Get() &&
      m_worlds[0]->GetConfig().THREAD_SLICING_METHOD.Get() != 1 && !m_worlds[0]->GetConfig().IMPLICIT_REPRO_END.Get() && point_mut_prob == 0.0) {
    ActiveProcessStep = &cPopulation::ProcessStepSpeculative;
  }*/
  
  //cAvidaContext* ctx = &m_worlds[0]->GetDefaultContext();¨
  //cout << "here" << endl;
  cAvidaContext* ctxs[n_worlds];
  //cout << "here 2" << endl;
  //Avida::Context new_ctxs;
  for (int i=0; i<n_worlds;i++){
    ctxs[i] = &m_worlds[i]->GetDefaultContext();
    //new_ctxs = Avida::Context(this, &m_worlds[i]->GetRandom());
  }
//   cAvidaContext* ctxs[n_worlds];
//   ctxs[0] = &m_worlds[0]->GetDefaultContext();
//Avida::Context new_ctx(this, &m_worlds[0]->GetRandom());
  
  m_god->speak();
  int dangerous_count = 0;//m_worlds[0]->GetStats().GetTaskCurCount(m_god->m_dangerous_op);
  
  while (!m_done) {
    
    for (int i=0;i<n_worlds;i++){
    m_worlds[i]->GetEvents(*ctxs[i]);
    if(m_done == true) break;
    
    // Increment the Update.
    stats[i]->IncCurrentUpdate();
    
    population[i]->ProcessPreUpdate();

    // Handle all data collection for previous update.
    if (stats[i]->GetUpdate() > 0) {
      // Tell the stats object to do update calculations and printing.
      stats[i]->ProcessUpdate();
    }
    
    // Process the update.
    // query the world to calculate the exact size of this update:
    const int UD_size = m_worlds[i]->CalculateUpdateSize();
    const double step_size = 1.0 / (double) UD_size;
    
    for (int i = 0; i < UD_size; i++) {
      if(population[i]->GetNumOrganisms() == 0) {
        break;
      }
      (population[i]->*ActiveProcessStep)(*ctxs[i], step_size, population[i]->ScheduleOrganism());
    }
    
    // end of update stats...
    population[i]->ProcessPostUpdate(*ctxs[i]);
		m_worlds[i]->ProcessPostUpdate(*ctxs[i]);

        
    // No viewer; print out status for this update....
    if (m_worlds[i]->GetVerbosity() > VERBOSE_SILENT) {
      cout.setf(ios::left);
      cout.setf(ios::showpoint);
      cout << "UD: " << setw(6) << stats[i]->GetUpdate() << "  ";
      cout << "Gen: " << setw(9) << setprecision(7) << stats[i]->SumGeneration().Average() << "  ";
      cout << "Fit: " << setw(9) << setprecision(7) << stats[i]->GetAveFitness() << "  ";
      cout << "Orgs: " << setw(6) << population[i]->GetNumOrganisms() << "  ";
      if (m_worlds[i]->GetPopulation().GetNumDemes() > 1) cout << "Demes: " << setw(4) << stats[i]->GetNumOccupiedDemes() << " ";
      if (m_worlds[i]->GetVerbosity() == VERBOSE_ON || m_worlds[i]->GetVerbosity() == VERBOSE_DETAILS) {
        cout << "Merit: " << setw(9) << setprecision(7) << stats[i]->GetAveMerit() << "  ";
        cout << "Thrd: " << setw(6) << stats[i]->GetNumThreads() << "  ";
        cout << "Para: " << stats[i]->GetNumParasites() << "  ";
      }
      if (m_worlds[i]->GetVerbosity() >= VERBOSE_DEBUG) {
        cout << "Spec: " << setw(6) << setprecision(4) << stats[i]->GetAveSpeculative() << "  ";
        cout << "SWst: " << setw(6) << setprecision(4) << (((double)stats[i]->GetSpeculativeWaste() / (double)m_worlds[i]->CalculateUpdateSize()) * 100.0) << "%  ";
      }

      // GOD TERMINATES PROGRAM
      dangerous_count = m_worlds[i]->GetStats().GetTaskCurCount(m_god->m_dangerous_op);
      cout << "GOD: dangerous op : " << dangerous_count;
      if (dangerous_count > 0){
        // Save populations and stats etc etc
        m_worlds[i]->GetDriver().Finish();
      }
      // #####################
  
      cout << endl;
    }
    
    
    // Do Point Mutations # PERHAPS WE SHOULD DISSALOW FOR THIS!!!
    if (point_mut_prob > 0 ) {
      for (int i = 0; i < population[i]->GetSize(); i++) {
        if (population[i]->GetCell(i).IsOccupied()) {
          int num_mut = population[i]->GetCell(i).GetOrganism()->GetHardware().PointMutate(*ctxs[i]);
          population[i]->GetCell(i).GetOrganism()->IncPointMutations(num_mut);
        }
      }
    }
    
    // m_new_worlds[i]->PerformUpdate(new_ctxs, stats[i]->GetUpdate());
    
    // Exit conditons...
    if((population[i]->GetNumOrganisms()==0) && m_worlds[i]->AllowsEarlyExit()) {
			m_done = true;
		}
    }
  }
}

void AvidaMetaDriver::Abort(Avida::AbortCondition condition)
{
  exit(condition);
}

void AvidaMetaDriver::StdIOFeedback::Error(const char* fmt, ...)
{
  printf("error: ");
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}

void AvidaMetaDriver::StdIOFeedback::Warning(const char* fmt, ...)
{
  printf("warning: ");
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}

void AvidaMetaDriver::StdIOFeedback::Notify(const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  printf(fmt, args);
  va_end(args);
  printf("\n");
}


