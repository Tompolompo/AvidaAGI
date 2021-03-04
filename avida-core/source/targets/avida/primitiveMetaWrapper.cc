#include <iostream>
#include <fstream>
#include <algorithm>
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
#include "INIReader.h"

using namespace std;

// Global parameters
int universe_settings[4] = {-1, -1, -1, -1}; // Denna måste se ut såhär om cmdline args ska overrida configfilen
int argc_avida;

int main(int argc, char **argv)  {
 
    // Read cmd-line arguments and set parameters
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Load parameters and settings from meta config
    INIReader reader("metaconfig.ini"); // Filen ligger i root-dir för att komma med i git men ska ligga i work för att hittas
    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'metaconfig.ini'\n";
        return 1;
    }

    // Genetic parameters
    int gene_min = reader.GetInteger("genetic", "gene_min", -10);
    int gene_max = reader.GetInteger("genetic", "gene_max", 10);
    double tournament_probability = reader.GetReal("genetic", "tournament_probability", 0.8);
    double crossover_probability = reader.GetReal("genetic", "crossover_probability", 0.3);
    double mutation_probability_constant = reader.GetReal("genetic", "mutation_probability_constant", 3);
    double mutation_decay = reader.GetReal("genetic", "mutation_decay", 0.95);
    double min_mutation_constant = reader.GetReal("genetic", "mutation_decay", 0.5);
    double creep_probability = reader.GetReal("genetic", "mutation_decay", 0.95);
    double creep_decay = reader.GetReal("genetic", "mutation_decay", 0.98);

    // Control settings
    std::vector<double> ref_chromosome = Str2DoubleVector(reader.Get("control", "ref_chromosome", "1 1 2 2 3 3 4 4 5"));
    bool binary = reader.GetBoolean("control", "binary_chromosome", false);
    int dangerous_op = reader.GetInteger("control", "dangerous_op", -1);

    // Iteration limits
    int num_worlds = reader.GetInteger("iterations", "num_worlds", 20);
    int num_meta_generations = reader.GetInteger("iterations", "num_meta_generations", 5);
    int num_updates = reader.GetInteger("iterations", "num_updates", 100);

    // General settings
    bool save_updates = reader.GetBoolean("general", "save_updates", true);
    std::string save_folder = reader.Get("general", "save_folder_name", "run");

    // Overwrite configfile params with cmdline arguments
    num_worlds = (universe_settings[0] != -1) ? universe_settings[0] : num_worlds;
    num_meta_generations = (universe_settings[1] != -1) ? universe_settings[1] : num_meta_generations;
    num_updates = (universe_settings[2] != -1) ? universe_settings[2] : num_updates;
    universe_settings[0] = num_worlds;
    universe_settings[1] = num_meta_generations;
    universe_settings[2] = num_updates;

    // Derived params
    int chromosome_length = ref_chromosome.size();
    double mutation_probability = mutation_probability_constant/chromosome_length;
    double creep_rate = (gene_max-gene_min)/3.0;
    double min_creep = (gene_max-gene_min)/25.0;
    if (binary) creep_probability = 1;

    // Set number of threads
    size_t n_threads = omp_get_max_threads();
    if (n_threads > num_worlds) n_threads = num_worlds;

    // Initialise starting conditions
    cGod* god = new cGod(universe_settings);
    std::vector<double> best_chromosome(chromosome_length, 0);
    std::vector<std::vector<double> > controllers;
    double max_fitness;
    std::vector<double> current_fitness(num_worlds, 0);
    int imeta = universe_settings[3];
    
    // Save settings
    FileSystem fs = FileSystem(imeta);
    if (imeta == 0) {
        fs.SaveSettings(num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep, ref_chromosome.data(), chromosome_length);
        fs.InitMetaData(chromosome_length);
        controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max, binary);
    }
    else    {
        controllers = fs.ReadChromosomes(num_worlds, chromosome_length);
    }
    fs.InitUpdateDirectory(imeta);

    // Initialise Avida
    Avida::Initialize();
    Apto::Map<Apto::String, Apto::String> defs;
    cAvidaConfig* cfg = new cAvidaConfig();
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv, cfg, defs);
    cfg->RANDOM_SEED.Set(imeta);


    // Run for each controller
    #pragma omp parallel for num_threads(n_threads)
    for (int iworld = 0; iworld < num_worlds; iworld++) {

        // Initialise world
        Avida::World* new_world = new Avida::World();
        cUserFeedback feedback;
        cWorld* world = new cWorld(cfg, cString(Apto::FileSystem::GetCWD()));

        // Set up world and controller 
        double *chromosome = controllers[iworld].data();
        world->setup(new_world, &feedback, &defs, ref_chromosome.data(), chromosome, chromosome_length);
        world->SetVerbosity(0);

        // Run simulation and compute fitness
        Avida2MetaDriver* driver = new Avida2MetaDriver(world, new_world, god);
        bool save = (iworld == 0) ? true : false;
        current_fitness[iworld] = driver->Run(fs, save, iworld, chromosome_length);

        // Clean up
        delete driver;
        // delete world;
        // delete new_world;
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
        if (RandomNumber(0.0, 1.0) < crossover_probability) {
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
        controllers[iworld] = Mutate(chromosome, mutation_probability, creep_rate, creep_probability, gene_min, gene_max, binary);
    }

    //Elitism
    controllers[0] = best_chromosome;

    // Print progress
    if (imeta%1 == 0)  {
        cout << "Meta Generation: " << imeta << ", Fitness: " << max_fitness << ", Best chromosome: [";
        for (size_t task = 0; task < chromosome_length; task++){
            cout << best_chromosome[task] << ", ";
        }
        cout << "] ";
    }

    // Save data to file
    fs.SaveMetaData(chromosome_length, imeta, max_fitness, best_chromosome);

    // Save chromosomes to file (to be able to continue at last imeta)
    fs.SaveChromosomes(controllers, num_worlds, chromosome_length);
    
    // Clean up
    delete[] argv_avida;
    delete god, cfg;

}

