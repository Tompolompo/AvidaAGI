#include <iostream>
#include <fstream>
#include <omp.h>
#include <algorithm>
#include <chrono> 

#include "AvidaTools.h"
#include "apto/core/FileSystem.h"
#include "avida/Avida.h"
#include "avida/core/World.h"
#include "avida/output/Manager.h"
#include "avida/util/CmdLine.h"
#include "cAvidaConfig.h"
#include "cUserFeedback.h"
#include "cWorld.h"
//#include "cStringUtil.h"
//#include "cStringIterator.h"

#include "GeneticFunctions.h"
#include "Avida2MetaDriver.h"
#include "cGod.h"
#include "FileSystem.h"

using namespace std;


// Global parameters
int universe_settings[4] = {1, 1, 1000, 0};
int argc_avida;

int main(int argc, char *argv[])  {

    // Parse cmd-line arguments and extract avida params to pass on
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Genetic parameters
    double gene_min = -1; 
    double gene_max = 7;
    int num_worlds = universe_settings[0];
    int num_meta_generations = universe_settings[1];
    int num_updates = universe_settings[2];
    int imeta = universe_settings[3];
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
    size_t n_threads = omp_get_max_threads();
    if (n_threads > num_worlds) n_threads = num_worlds;

    // Save settigns to file [make separate function for this]
    std::vector<double> Phi_0 = std::vector<double>(chromosome_length, 0);
    Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;    

    // Initialise god, result arrays and starting conditions
    cGod* God = new cGod(universe_settings);
    std::vector<double> best_chromosome(chromosome_length, 0);
    std::vector<double> current_fitness(num_worlds, 0);
    std::vector<std::vector<double> > controllers;
    double current_max_fitness = -666;

    FileSystem fs = FileSystem(imeta);
    if (imeta==0)   {
        // save settings and initialize run file
        fs.SaveSettings(num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep, Phi_0, chromosome_length);
        fs.InitMetaData(chromosome_length);
        controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);
    }
    else    {
        // read chromosomes from file
        controllers = fs.ReadChromosomes(num_worlds, chromosome_length);
    }
    fs.InitUpdateDirectory(42);

    // Initialise avida stuff
    Avida::Initialize(); // Initialize...
    // cout << Avida::Version::Banner() << endl; // print the banner and current version of Avida
    Apto::Map<Apto::String, Apto::String> defs; // define a map that maps an apto string to an apto string
    cAvidaConfig* cfg = new cAvidaConfig(); // define our avida configuration file /new callar på constructor) can overridea config-filen osv. 
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv_avida, cfg, defs); // sätter på settings som användaren gör i command line. typ sätt på analyze mode etc 
    cfg->RANDOM_SEED.Set(imeta);
    cUserFeedback feedback; //visar varningsmedelanden osv till användaren

    // Timing
    /*
    auto start = std::chrono::high_resolution_clock::now(); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start); */

    // Process all worlds
    #pragma omp parallel num_threads(n_threads)
    {
    #pragma omp for
    for (size_t iworld = 0; iworld < num_worlds; iworld++) {

        // Initialize world
        Avida::World *new_world = new Avida::World();
        cWorld *world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs);
        
        // Load controller chromosome
        double *chromosome = controllers[iworld].data();
        //double Phi0[9];

        //Phi0[0]=5;Phi0[1]=5;Phi0[2]=5;Phi0[3]=5;Phi0[4]=5;Phi0[5]=5;Phi0[6]=4;Phi0[7]=4;Phi0[8]=5;             
        world->m_ctx->m_controller.SetChromosome(chromosome, chromosome_length);
        world->setup(new_world, &feedback, &defs);
        world->SetVerbosity(0);

        // Run avida simulation and evaluate controller
        Apto::SmartPtr<Avida2MetaDriver> driver(new Avida2MetaDriver(world, new_world, God));
        current_fitness[iworld] = driver.GetPointer(driver)->Run(fs, iworld);
        // current_fitness[iworld] = EvaluateController(chromosome, chromosome_length);
        
    }
    }

    // // test print of chromosomes
    // for (int iworld=0; iworld<num_worlds; iworld++){
    //     cout <<  "Fitness: " << current_fitness[iworld] << " Chromosome: [";
    //     for (int igene=0; igene<chromosome_length; igene++){;
    //         std::cout << controllers[iworld][igene] << " ";
    //     }
    //     std::cout << "]" << endl;
    // }

    // Update best results so far
    int imax = std::max_element(current_fitness.begin(),current_fitness.end()) - current_fitness.begin();
    best_chromosome = controllers[imax];
    current_max_fitness = current_fitness[imax];

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
    /*
    end = std::chrono::high_resolution_clock::now(); 
    duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);*/
    if (imeta%1 == 0)  {
        cout << "Meta Generation: " << imeta << ", Fitness: " << current_max_fitness << ", Best chromosome: [";
        for (size_t task = 0; task < chromosome_length; task++){
            cout << best_chromosome[task] << ", ";
        }
        cout << "] ";
    }


    // Save data to file
    fs.SaveMetaData(chromosome_length, imeta, current_max_fitness, best_chromosome);

    // Save chromosomes to file
    fs.SaveChromosomes(controllers, num_worlds, chromosome_length);

    return 0;
}

