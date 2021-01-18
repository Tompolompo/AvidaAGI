/*
 *  primitive.cc
 *  Avida
 *
 *  Copyright 1999-2011 Michigan State University. All rights reserved.
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
 */

#include "AvidaTools.h"

#include "apto/core/FileSystem.h"
#include "avida/Avida.h"
#include "avida/core/World.h"
#include "avida/output/Manager.h"
#include "avida/util/CmdLine.h"

#include "cAvidaConfig.h"
#include "cUserFeedback.h"
#include "cWorld.h"

#include "Avida2Driver.h"
#include "cGod.h"


int main(int argc, char * argv[])
{

  Avida::Initialize(); // Initialize...
  
  cout << Avida::Version::Banner() << endl; // print the banner and current version of Avida

  // Initialize the configuration data...
  Apto::Map<Apto::String, Apto::String> defs; // define a map that maps an apto string to an apto string
  cAvidaConfig* cfg = new cAvidaConfig(); /* define our avida configuration file /new callar på constructor) can overridea config-filen osv. */
  Avida::Util::ProcessCmdLineArgs(argc, argv, cfg, defs); // sätter på settings som användaren gör i command line. typ sätt på analyze mode etc 
  
  cUserFeedback feedback; //visar varningsmedelanden osv till användaren
  Avida::World* new_world = new Avida::World(); /* constructor för Avida::World (/source/core/world.cc). gör inte så mycket här. typ initalizerar (framtida performe update)*/
  cWorld* world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs); 
  /* i cWorld finns klasser om organism, population, merit, environment osv. mycket centralt. cWorld. kallar på sin egen constructor och kör setup 
  av cWorld. 
  - cWorld kallar på cAvidaContext: denna har en world driver. verkar kontrollerar inställningssettings. analyse/tsting organism_faults
      - WorldDriver: (interface for objects that drive world exucution): (LIB_EXPORT) , PAUSE, FINISH, ABORT (kanske är en grundklass som ärvs och skrivs över)
  - (API?)
  - skapar new cEnvironment(this): styr environment, tasks, reactions, resources, phenotype, 
      - skapar array of cStateGrid's (typ varje organisms plats i världen)
      - configurerar environment från configfil (tar filename och working directory) setters, getters global variables angående environment
  - skapar new cMigrationMatrix
      - offspring count, Deme, parasite. förmodligen ointressant
  -Initialize the default environment. tar in configfilen
  -(migration)
  -systematic
  -set up stats object manager
  -hardware manager - instruction sets (nop A, nop B...), configfiler. ska nog låtas vara
  -constant booleans med massa värden från configfilerna (environment.cfg(?!))
  -m_pop: new population (cPopulation):
      - massa populationkommandon. offspring, parasite, resizecell grid, kill organism (Kan vi behöva använda)minjure, demes, flagged germline, 
      calculate statistics, SAVE POPULATION, LOAD POPULATION, update resources, getenvironment, update merit. let users change environment during the run.
      fill empty cell, injectclone, activateorganism, LOAD GENOTPE LIST. activate offspring Här skulle vi kunna ta vår controller och ändra i genomet 
      innan vi sätter ut offspring i världen. birth_chamber. placerar ut organism i världen igen. 
      - cOrganism: initial genome, offspring genome. gettestfitness. getters setters. test divide, test copy. 
  - setup eventlist: set up från configfil. 
  - GetStatsProvider (return m_stats)
  - GetPopulationProvider (return m_pop)
  - m_analyze
  - get events
  */

// fel och eller varningar?
  for (int i = 0; i < feedback.GetNumMessages(); i++) {
    switch (feedback.GetMessageType(i)) {
      case cUserFeedback::UF_ERROR:    cerr << "error: "; break;
      case cUserFeedback::UF_WARNING:  cerr << "warning: "; break;
      default: break;
    };
    cerr << feedback.GetMessage(i) << endl;
  }

  if (!world) return -1; //felhantering
  
  // set up random seed och printar seeden
  const int rand_seed = world->GetConfig().RANDOM_SEED.Get(); 
  cout << "Random Seed: " << rand_seed;
  if (rand_seed != world->GetRandom().Seed()) cout << " -> " << world->GetRandom().Seed();
  cout << endl;

  // output path print. data directory 
  if (world->GetConfig().VERBOSITY.Get() > VERBOSE_NORMAL)
    cout << "Data Directory: " << Avida::Output::Manager::Of(new_world)->OutputPath() << endl;

  cout << endl; // byter rad

  
  cGod* God = new cGod(0, 1, 0 , 0);

  (new Avida2Driver(world, new_world, God))->Run(); /* BOOM. kör skiten 
  - world cWorld (riktiga), new_world (Avida::World)
  - hämtar in population från cWorld
  - hämtar in stats från cWorld
  - allmänna settings från cworld
  - cpopulation:processStep (initalisera (?!))
      - tar ut organismen från cell. kollar CPU. tar ut merit. stats. kör instruktionerna för en organism 
  - while loop genom alla organismer och uppdaterar
    - hämtar in events
    - increment current update
    - process pre update
    - handle data collection
    - beräknar storleken på update --> step size
    - for int i < update_Size
      - population.*ActiveProcessstep: kör ett steg för en organism.
      - kör genom alla till vi har nått vår update size. 
    - Kollar vi post update. uppdaterar. berkänar osv både population och cWorld
    - printar efter varje update. 
    - utför point mutations och uppdaterar World (new_world)
  
  */
  return 0;
}
