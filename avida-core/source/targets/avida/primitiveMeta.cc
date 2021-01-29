#include <iostream>
#include <fstream>
// #include <unistd.h>

#include "AvidaTools.h"
#include "apto/core/FileSystem.h"
#include "avida/Avida.h"
#include "avida/core/World.h"
#include "avida/output/Manager.h"
#include "avida/util/CmdLine.h"
#include "cAvidaConfig.h"
#include "cUserFeedback.h"
#include "cWorld.h"

#include "GeneticFunctions.h"
#include "Avida2MetaDriver.h"
#include "cGod.h"
#include <chrono> 
//#include "cStringUtil.h"
//#include "cStringIterator.h"

using namespace std;


// Global parameters
int universe_settings[4] = {20, 50, 3000, 9};
int argc_avida;

int main(int argc, char *argv[])  {

    // Parse cmd-line arguments and extract avida params to pass on
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Genetic parameters
    double gene_min = 0; 
    double gene_max = 7;
    size_t num_worlds = universe_settings[0];
    size_t num_generations  = universe_settings[1];
    size_t num_updates = universe_settings[2];
    size_t chromosome_length = 9;
    double tournament_probability = 0.8;
    double crossover_probability = 0.7;
    double mutation_probability_constant = 5*1/chromosome_length;
    double mutation_probability = mutation_probability_constant;
    double creep_rate = (gene_max-gene_min)/10;
    double creep_probability =0.90;

    // Save settigns to file [make separate function for this]
    double Phi_0[chromosome_length];
    Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;
    
    FILE *file_settings = fopen("data/AGIdata/settings.csv", "w");
    fprintf(file_settings, "N,M,I,tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, gene_min, gene_max, creep_rate, creep_probability");
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_settings, ",hatPhi_0[%d]", task);
    }
    fprintf(file_settings, "\n");
    fprintf(file_settings, "%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f", num_worlds, num_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, gene_min, gene_max,  creep_rate, creep_probability);
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_settings, ",%f", Phi_0[task]);
    }
    fprintf(file_settings, "\n");
    fclose(file_settings);
    

    // Initialise god, result arrays and starting conditions
    cGod* God = new cGod(universe_settings);
    God->speak();
    std::vector<double> best_fitness(num_generations, 0);
    double best_chromosome[chromosome_length];
    std::vector<double> current_fitness(num_worlds, 0);
    std::vector<std::vector<double> > controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);

    // Initialise avida stuff
    Avida::Initialize(); // Initialize...
    // cout << Avida::Version::Banner() << endl; // print the banner and current version of Avida
    Apto::Map<Apto::String, Apto::String> defs; // define a map that maps an apto string to an apto string
    cAvidaConfig* cfg = new cAvidaConfig(); /* define our avida configuration file /new callar på constructor) can overridea config-filen osv. */
    
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv_avida, cfg, defs); // sätter på settings som användaren gör i command line. typ sätt på analyze mode etc 
    cfg->RANDOM_SEED.Set(42);

    cUserFeedback feedback; //visar varningsmedelanden osv till användaren
    cout << "Universe settings: " << num_worlds << " worlds, " << num_generations << " meta generations, " << num_updates << " updates, " << endl;
    cout << "Starting Meta evolution " << endl;

    FILE *file_meta_run = fopen("data/AGIdata/metarun.csv", "w");
    fprintf(file_meta_run, "m,max(Phi_0)");
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_meta_run, ",hatphi%d", task);
    }
    fprintf(file_meta_run, "\n");

    FILE *file_run = fopen("data/AGIdata/run.csv", "w");
    fprintf(file_run, "UD,Gen,phi_i,phi_0,orgs,task0,task1,task2,task3,task4,task5,task6,task7,task8\n");

    // Main loop over meta generations
    auto start = std::chrono::high_resolution_clock::now(); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - start); 

    // temporary
    double *chromosome = controllers[0].data();

    for (size_t imeta = 0; imeta < num_generations; imeta++)   {
        start = std::chrono::high_resolution_clock::now(); 
        
        double current_max_fitness = -99999;
        for (size_t iworld = 0; iworld < num_worlds; iworld++) {
            
            // Initialize world
            Avida::World *new_world = new Avida::World();
            cWorld *world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs);

            // Load controller chromosome
            //double *chromosome = controllers[iworld].data();
            for (int i=0; i< chromosome_length; i++){
                chromosome[i]=Phi_0[i]*(iworld*2+1);
            }
            
            world->m_ctx->m_controller.SetChromosome(chromosome, chromosome_length);
            world->setup(new_world, &feedback, &defs);
            //world->SetVerbosity(0);

            // Run avida simulation and evaluate controller
            Avida2MetaDriver driver = Avida2MetaDriver(world, new_world, God);
            driver = driver.Run(file_run);
            fprintf(file_run, "-,-,-,-,-,-,-,-,-,-,-,-,-,-\n");
            current_fitness[iworld] = driver.m_stats->GetPhi0Fitness();
            // current_fitness[iworld] = EvaluateController(chromosome, chromosome_length);

            // clean up
            driver.~Avida2MetaDriver(); 

            // Update best results so far
            if (current_fitness[iworld] >= current_max_fitness)  {
                current_max_fitness = current_fitness[iworld];
                std::copy(chromosome, chromosome+chromosome_length, best_chromosome);
            }
        }

        // Selection
        std::vector<std::vector<double> > new_controllers = controllers;
        for (size_t iworld = 0; iworld < num_worlds-1; iworld += 2) {

            // Select a pair of chromosomes
            size_t ix1 = TournamentSelect(current_fitness, tournament_probability);
            size_t ix2 = TournamentSelect(current_fitness, tournament_probability);
            new_controllers[iworld] = controllers[ix1];
            new_controllers[iworld+1] = controllers[ix2];

            // Crossover
            if (RandomNumber('r', 0, 1) < crossover_probability) {
                std::vector<std::vector<double> > chromosomes = Cross(controllers[ix1], controllers[ix2]);
                new_controllers[iworld] = chromosomes[0];
                new_controllers[iworld+1] = chromosomes[1];
            }
        }

        // Mutation
        mutation_probability_constant = mutation_probability_constant/(0.1*imeta + 1);
        mutation_probability = mutation_probability_constant/chromosome_length;
        for (size_t iworld = 0; iworld < num_worlds; iworld++) {
            std::vector<double> chromosome = new_controllers[iworld];
            controllers[iworld] = Mutate(chromosome, mutation_probability, creep_rate, creep_probability, gene_min, gene_max);
        }

        //Elitism
        std::vector<double> best(best_chromosome, best_chromosome + chromosome_length);
        controllers[0] = best;

        // Print progress
        end = std::chrono::high_resolution_clock::now(); 
        duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
         if (imeta%1 == 0)  {
            cout << "Meta Generation: " << imeta << ", Fitness: " << current_max_fitness << ", Best chromosome: [";
            for (int task = 0; task < chromosome_length; task++){
                cout << best[task] << ", ";
            }
            cout << "] elapsed: " << duration.count() << " min" << endl;
        }

        // Save data to file
        fprintf(file_meta_run, "%d,%f", imeta, current_max_fitness);
        for (int task = 0; task < chromosome_length; task++){
            fprintf(file_meta_run, ",%f", best[task]);
        }
        fprintf(file_meta_run, "\n");
        

    }
    fclose(file_meta_run);
    fclose(file_run);
    
    // Final cleaning
    free(argv_avida);

    return 0;
}

