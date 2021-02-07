#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
// #include <thread>
#include <omp.h>

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

#include "GeneticFunctions.h"
#include "FileSystem.h"
#include "cGod.h"

using namespace std;

// Global parameters
int universe_settings[4] = {5, 3, 50, 0};
int argc_avida;

void Evaluate(int ix, double* chromosome, int length, std::vector<double> &fitness, char **argv, cGod *god, Apto::Map<Apto::String, Apto::String> defs, cAvidaConfig* cfg)  {


    // Initialise world
    Avida::World* new_world = new Avida::World();
    cUserFeedback feedback;
    cWorld* world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs);

    // Set up world and controller          
    world->m_ctx->m_controller.SetChromosome(chromosome, length);
    world->setup(new_world, &feedback, &defs);
    world->SetVerbosity(0);

    // Run simulation and compute fitness
    // fitness[ix] = ( (new Avida2MetaDriver(world, new_world, god))->Run() );
    // fitness[ix] = EvaluateController(chromosome, length);

    Avida2MetaDriver* driver = new Avida2MetaDriver(world, new_world, god);
    double tmp = driver->Run();
    fitness[ix] = tmp;

    // delete driver;

    
}

int main(int argc, char **argv)  {
 
    // Read cmd-line arguments and set parameters
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Genetic parameters
    double gene_min = 0; 
    double gene_max = 7;
    int num_worlds = universe_settings[0];
    int num_meta_generations = universe_settings[1];
    int num_updates = universe_settings[2];
    int chromosome_length = 9;
    double tournament_probability = 0.8;
    double crossover_probability = 0.3;
    double mutation_probability_constant = 3.0;
    double mutation_probability = mutation_probability_constant/chromosome_length;
    double mutation_decay = 0.95;
    double min_mutation_constant = 0.5;
    double creep_rate = (gene_max-gene_min)/3.0;
    double creep_probability = 0.9;
    double creep_decay = 0.98;
    double min_creep = (gene_max-gene_min)/25.0;

    // Set number of threads
    size_t n_threads = omp_get_max_threads(); //std::thread::hardware_concurrency();
    if (n_threads > num_worlds) n_threads = num_worlds;
    std::cout << "Running with " << n_threads << " threads" << std::endl;
    // std::vector<std::thread> threads(num_worlds);

    // Initialise starting conditions
    cGod* God = new cGod(universe_settings);
    std::vector<double> best_chromosome(chromosome_length, 0);
    std::vector<std::vector<double> > controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);
    // std::vector<double> Phi_0 = std::vector<double>(chromosome_length, 0);
    // Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;
    
    // Initialise Avida
    Avida::Initialize();
    Apto::Map<Apto::String, Apto::String> defs;
    cAvidaConfig* cfg = new cAvidaConfig();
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv, cfg, defs);


    // Timing
    auto start = std::chrono::high_resolution_clock::now(); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start); 

    // Main loop over meta generations
    for (size_t imeta = 0; imeta < num_meta_generations; imeta++)   {

        std::vector<double> current_fitness(num_worlds, 0);
        double max_fitness = 0;
        cfg->RANDOM_SEED.Set(imeta); // Hur bör denna sättas?
        
        
        // FileSystem fs = FileSystem(imeta);
        // if (imeta==0)   {
        //     // save settings and initialize run file
        //     fs.SaveSettings(num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep, Phi_0, chromosome_length);
        //     fs.InitMetaData(chromosome_length);
        //     // controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);
        // }
        // else    {
        //     // read chromosomes from file
        //     // controllers = fs.ReadChromosomes(num_worlds, chromosome_length);
        // }
        // fs.InitUpdateDirectory(imeta);

        // Run for each controller
        #pragma omp parallel for
        for (int iworld = 0; iworld < num_worlds; iworld++) {

 
            // Evaluate the controller
            double *chromosome = controllers[iworld].data();
            // threads[iworld] = std::thread(Evaluate, iworld, chromosome, chromosome_length, std::ref(current_fitness), std::ref(argv_avida), std::ref(God), std::ref(defs), std::ref(cfg));
            Evaluate(iworld, chromosome, chromosome_length, std::ref(current_fitness), std::ref(argv_avida), std::ref(God), std::ref(defs), std::ref(cfg));

            

        }

        // Wait for all worlds to complete
        // for (std::thread &th : threads) {
        //     th.join();
        // }
        

        // Update best results so far
        int imax = std::max_element(current_fitness.begin(),current_fitness.end()) - current_fitness.begin();
        best_chromosome = controllers[imax];
        max_fitness = current_fitness[imax];

        // Selection
        std::vector<std::vector<double> > new_controllers = controllers;
        for (size_t iworld = 0; iworld < num_worlds-1; iworld += 2) {

            // Select a pair of chromosomes
            int ix1 = TournamentSelect(current_fitness, tournament_probability);
            int ix2=-1;
            do { ix2 = TournamentSelect(current_fitness, tournament_probability); }
            while (ix2==ix1);
            
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
        mutation_probability_constant = mutation_probability_constant*pow(mutation_decay,imeta)+min_mutation_constant;
        mutation_probability = mutation_probability_constant/chromosome_length;
        creep_rate = creep_rate*pow(creep_decay, imeta) + min_creep;
        for (size_t iworld = 0; iworld < num_worlds; iworld++) {
            std::vector<double> chromosome = new_controllers[iworld];
            controllers[iworld] = Mutate(chromosome, mutation_probability, creep_rate, creep_probability, gene_min, gene_max);
        }

        //Elitism
        controllers[0] = best_chromosome;

        // Print progress
        end = std::chrono::high_resolution_clock::now(); 
        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            if (imeta%1 == 0)  {
            cout << "Meta Generation: " << imeta << ", Fitness: " << max_fitness << ", Best chromosome: [";
            for (size_t task = 0; task < chromosome_length; task++){
                cout << best_chromosome[task] << ", ";
            }
            cout << "] elapsed: " << duration.count() << " seconds" << endl;
        }

        // // Save data to file
        // fs.SaveMetaData(chromosome_length, imeta, max_fitness, best_chromosome);

        // // Save chromosomes to file
        // fs.SaveChromosomes(controllers, num_worlds, chromosome_length);

    }

    
    // Clean up
    delete[] argv_avida;
    delete God;
    delete cfg;

    std::cout << "simulation finished" << std::endl;
}

