/*
 *  Avida2Driver.h
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

#ifndef Avida2MetaDriver_h
#define Avida2MetaDriver_h

#include "avida/core/Feedback.h"
#include "avida/core/Types.h"
#include "avida/core/WorldDriver.h"
#include "cGod.h"

#include "cPopulation.h"
#include "cStats.h"
#include "cWorld.h"
#include "avida/core/Context.h"

class cWorld;


class Avida2MetaDriver : public Avida::WorldDriver
{
protected:
  Avida::World* m_new_world;
  cGod* m_god;
  bool m_done;
  
  class StdIOFeedback : public Avida::Feedback
  {
    void Error(const char* fmt, ...);
    void Warning(const char* fmt, ...);
    void Notify(const char* fmt, ...);
  } m_feedback;
  
public:
  Avida2MetaDriver();
  Avida2MetaDriver(cWorld* world, Avida::World* new_world, cGod* God);
  ~Avida2MetaDriver();

  cPopulation* m_population;
  cStats* m_stats;
  cAvidaContext* m_ctx;
  cWorld* m_world;
  //Avida::Context m_new_ctx;  

  void (cPopulation::*ActiveProcessStep)(cAvidaContext& ctx, double step_size, int cell_id) = &cPopulation::ProcessStep;
  
  
  // Actions
  Avida2MetaDriver Run();
  Avida2MetaDriver Continue();
  void UpdateStats();
  void ReplacePopulation(cPopulation* new_population);

  void Finish() { m_done = true; }
  void Pause() { return; }
  void Abort(Avida::AbortCondition condition);
  
  // Facilities
  Avida::Feedback& Feedback() { return m_feedback; }

  // Callback
  void RegisterCallback(Avida::DriverCallback callback) { (void)callback; }
};

#endif
