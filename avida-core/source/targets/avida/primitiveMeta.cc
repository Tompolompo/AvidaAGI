#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>

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

// #include "cGod.h"
#include "GeneticFunctions.h"
#include "FileSystem.h"
#include "cGod.h"

using namespace std;

// Global parameters
int universe_settings[4] = {5, 3, 50, 0};
int argc_avida;


void EvaluateTest(int ix, double* chromosome, int length, std::vector<double> &fitness)  {

    
    // std::cout << "fitness[" << ix << "] = " << fitness[ix] << endl; 
}

void Evaluate(int ix, double* chromosome, int length, std::vector<double> &fitness, char **argv)  {

    // Initialize the configuration data...
    Apto::Map<Apto::String, Apto::String> defs;
    cAvidaConfig* cfg = new cAvidaConfig();
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv, cfg, defs);

    cUserFeedback feedback;
    Avida::World* new_world = new Avida::World();
    cWorld* world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs);
    world->SetVerbosity(0);
    // for (int i = 0; i < feedback.GetNumMessages(); i++) {
    //     switch (feedback.GetMessageType(i)) {
    //     case cUserFeedback::UF_ERROR:    cerr << "error: "; break;
    //     case cUserFeedback::UF_WARNING:  cerr << "warning: "; break;
    //     default: break;
    //     };
    //     cerr << feedback.GetMessage(i) << endl;
    // }

    // if (!world) cout << "Error creating world";

    // const int rand_seed = world->GetConfig().RANDOM_SEED.Get();
    // cout << "Random Seed: " << rand_seed;
    // if (rand_seed != world->GetRandom().Seed()) cout << " -> " << world->GetRandom().Seed();
    // cout << endl;

    // if (world->GetConfig().VERBOSITY.Get() > VERBOSE_NORMAL)
    //     cout << "Data Directory: " << Avida::Output::Manager::Of(new_world)->OutputPath() << endl;

    // cout << endl;

    Avida2MetaDriver *driver = new Avida2MetaDriver(world, new_world);
    driver->Run();
    fitness[ix] = EvaluateController(chromosome, length);

    // delete driver;

}

int main(int argc, char **argv)  {
 
    // Read cmd-line arguments and set parameters
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Genetic parameters
    double gene_min = 0; 
    double gene_max = 25;
    int num_worlds = universe_settings[0];
    int num_meta_generations = universe_settings[1];
    int num_updates = universe_settings[2];
    int chromosome_length = 9;
    double tournament_probability = 0.7;
    double crossover_probability = 0.7;
    double mutation_probability_constant = 1.0;
    double mutation_probability = mutation_probability_constant/chromosome_length;
    double mutation_decay= 1;
    double creep_rate = (gene_max-gene_min)/5.0;
    double creep_probability = 0.8;
    double creep_decay = 1;

    // Set number of threads
    size_t n_threads = std::thread::hardware_concurrency();
    if (n_threads > num_worlds) n_threads = num_worlds;
    std::cout << "Running with " << n_threads << " threads" << std::endl;
    std::vector<std::thread> threads(num_worlds);

    // Initialise god, result arrays and starting conditions
    cGod* God = new cGod(universe_settings);
    std::vector<double> best_chromosome(chromosome_length, 0);
    double max_fitness = 0;
    std::vector<std::vector<double> > controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);
    
    Avida::Initialize();
    // cout << Avida::Version::Banner() << endl;

    // Timing
    auto start = std::chrono::high_resolution_clock::now(); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start); 

    // Main loop over meta generations
    for (size_t imeta = 0; imeta < num_meta_generations; imeta++)   {

        std::vector<double> current_fitness(num_worlds, 0);

        

        // Run for each controller
        for (int iworld = 0; iworld < num_worlds; iworld++) {

            // Evaluate the controller
            double *chromosome = controllers[iworld].data();
            // threads[iworld] = std::thread(EvaluateTest, iworld, chromosome, chromosome_length, std::ref(current_fitness));
            threads[iworld] = std::thread(Evaluate, iworld, chromosome, chromosome_length, std::ref(current_fitness), std::ref(argv_avida));

        }

        // Wait for all worlds to complete
        for (auto &th : threads) {
            th.join();
        }

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
        mutation_probability = mutation_probability_constant/chromosome_length;
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

    }

    // Clean up
    delete[] argv_avida;
    delete God;

    std::cout << "simulation finished" << std::endl;
}

