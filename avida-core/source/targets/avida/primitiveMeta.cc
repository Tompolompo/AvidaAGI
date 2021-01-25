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

#include "Avida2MetaDriver.h"
#include "cGod.h"
//#include "cStringUtil.h"
//#include "cStringIterator.h"

int str2int(const char *s){
    int res = 0;
    while (*s) {
        res *= 10;
        res += *s++ - '0';
    }
    return res;
}


int main(int argc, char * argv[])
{

  Avida::Initialize(); // Initialize...
  
  cout << Avida::Version::Banner() << endl; // print the banner and current version of Avida

  int universe_settings[4];
  universe_settings[0] = str2int(argv[1]); // Number of worlds
  universe_settings[1] = str2int(argv[2]); // N meta generations
  universe_settings[2] = str2int(argv[3]);
  universe_settings[3] = 9; // dangerous op
  char * argv_new[1];
  argv_new[0] = argv[0];
  argc = 1;

  int N_worlds = universe_settings[0];
  int N_meta_generations  = universe_settings[1];
  int meta_generation_step_size = universe_settings[2];

  // Initialize the configuration data...
  Apto::Map<Apto::String, Apto::String> defs; // define a map that maps an apto string to an apto string
  cAvidaConfig* cfg = new cAvidaConfig(); /* define our avida configuration file /new callar på constructor) can overridea config-filen osv. */
  Avida::Util::ProcessCmdLineArgs(argc, argv_new, cfg, defs); // sätter på settings som användaren gör i command line. typ sätt på analyze mode etc 
  
  cUserFeedback feedback; //visar varningsmedelanden osv till användaren

  // CONSTRUCT a grid of worlds
  cout << "************** BIG BANG ****************" << endl;
  cout << "This is the begining of the universe" << endl;
  cGod* God = new cGod(universe_settings);
  God->speak();
  cout << "Constructing " << N_worlds << " worlds..." << endl;
  // Controller genomes
  int n_operations=9;
  double Phi_0[n_operations];
  Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;
  double temp_chromosome[n_operations];
  

  Avida::World* new_worlds[N_worlds];
  cWorld* worlds[N_worlds];
  bool test;
  for (int i=0; i<N_worlds;i++){
      cout << "World: " << i+1 << endl;
      new_worlds[i] = new Avida::World(); 
      cfg->RANDOM_SEED.Set(i+1);
      worlds[i] = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_worlds[i], &feedback, &defs);

      // Create arbitrary controller chromosome
      for (int j = 0; j < n_operations; j++)
      {
        temp_chromosome[j] = (j+1);//
      }
      worlds[i]->m_ctx->m_controller.SetChromosome(temp_chromosome, n_operations); // Load controller chromosome
      worlds[i]->setup(new_worlds[i], &feedback, &defs); // reinitialize cworld such that the correct chromosome is implemented
      
  }
  
  cout << "Which world will stand the test of time?" << endl;
  cout << "****************************************" << endl;
  cout << endl;

  for (int i = 0; i < feedback.GetNumMessages(); i++) {
    switch (feedback.GetMessageType(i)) {
      case cUserFeedback::UF_ERROR:    cerr << "error: "; break;
      case cUserFeedback::UF_WARNING:  cerr << "warning: "; break;
      default: break;
    };
    cerr << feedback.GetMessage(i) << endl;
  }

  if (!worlds) return -1; //felhantering
  
  // print random seed 
  int rand_seeds[N_worlds]; // (CONST)
  for (int i=0; i<N_worlds; i++){
      rand_seeds[i] = worlds[i]->GetConfig().RANDOM_SEED.Get();
      cout << "Random Seed world " << i+1 << " = " << rand_seeds[i];
      if (rand_seeds[i] != worlds[i]->GetRandom().Seed()) cout << " -> " << worlds[i]->GetRandom().Seed();
      cout << endl;
  }
  cout << endl;

  // output path print. data directory 
  for (int i=0; i<N_worlds; i++){
    cout << "Data Directory: " << Avida::Output::Manager::Of(new_worlds[i])->OutputPath() << endl;
  }
  cout << endl; 
  
  cout << "Constructing drivers:" << endl;
  Avida2MetaDriver drivers[N_worlds];
  for (int i=0; i<N_worlds; i++){
    cout << "Driver " << i+1 << endl;
    drivers[i] = Avida2MetaDriver(worlds[i], new_worlds[i], God);
  }
  cout << endl;
  cout << "Universe settings: " << N_worlds << " worlds, " << N_meta_generations << " Meta generations, " << meta_generation_step_size << " Meta generation step size." << endl;
  cout << "Entering Meta evolution " << endl;

 cout << "************************ Metageneration " << 0 << "*****************************" << endl;
 for (int i=0; i<N_worlds; i++){
     cout << "zeroth Metageneration on world " << i+1 << endl;
    drivers[i].Run();
  }
  cout << endl;

  FILE *file_chromosomes = fopen("data/AGIdata/chromosomes.csv", "w");
  fprintf(file_chromosomes, "World index, Meta generation" );
  for (int task = 0; task < n_operations; task++){ //m_world->GetEnvironment().GetNumReactions();
    //char task_name[32];
    //snprintf(ftask_name, sizeof(char) * 32, ",task %d", task); 
    fprintf(file_chromosomes, ",task %d value", task);
  }
  fprintf(file_chromosomes, "\n");

  fprintf(file_chromosomes, "%d,%d", 0, 0);
  for (int task = 0; task < n_operations; task++){ //m_world->GetEnvironment().GetNumReactions();
    //char task_name[32];
    //snprintf(ftask_name, sizeof(char) * 32, ",task %d", task); 
    fprintf(file_chromosomes, ",%f", temp_chromosome[task]);
  }
  fprintf(file_chromosomes, "\n");

  double fitness[N_worlds];
  int meta_generation = 0;
  int minIndex;
  int maxIndex;
  double min;
  double max;
  while (meta_generation < N_meta_generations-1)
  {
      // EVALUATE WORLDS
      // fitness functions
      min = 100000000;
      max= -100000000;
      cout << " Fitness: ";
      for (int i=0; i<N_worlds; i++){
          fitness[i] = drivers[i].m_stats->GetAveFitness() + (-100000)*drivers[i].m_world->GetStats().GetTaskCurCount(God->m_dangerous_op); // + time bonus + XOR punishment
          cout << fitness[i] << " ,";
          if (fitness[i] < min){
              minIndex = i;
              min = fitness[i];
          }
          if (fitness[i] > max){
              maxIndex = i;
              max = fitness[i];
          }

      }
      cout << "    Minimum fitness index = " << minIndex << endl;
      cout << "    Maximum fitness index = " << maxIndex << endl;

      // "Genetic algorithm":
      // replace the world with the lowest fitness with a new world

      if (N_worlds > 1){
        // new_worlds[minIndex] = new Avida::World(); 
        // cfg->RANDOM_SEED.Set(meta_generation*42);
        // worlds[minIndex] = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_worlds[minIndex], &feedback, &defs);
        // drivers[minIndex].Run();
        // drivers[minIndex].ReplacePopulation( drivers[maxIndex].m_population );
      }
      

      meta_generation++;
      cout << "************************ Metageneration update = " << meta_generation  << "*****************************" << endl;
      // Start next meta generation
      for (int i=0; i<N_worlds; i++){
        cout << endl;
        cout << "Continuing on World " << i + 1 << endl;
        drivers[i] = drivers[i].Continue();
      }
      
      cout << endl;
  }
  cout << "**********End of the universe***********" << endl;
  cout << "*****************-_-********************" << endl;

  return 0;
}
