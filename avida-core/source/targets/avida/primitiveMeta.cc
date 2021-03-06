#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include "mpi.h"

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
#include "INIReader.h"
#include <Eigen/Dense>

using namespace std;

/* Såhär kör man: X är antal processer.
    module load mpi (Behöver bara köras en gång)
    mpirun -np X ./avida -nN -mM -uU
*/


// Global parameters
int universe_settings[4] = {-1, -1, -1, -1}; // Denna måste se ut såhär om cmdline args ska overrida configfilen
int argc_avida;

int main(int argc, char **argv)  {

    // Initiate MPI and forward arguments
    MPI_Init(&argc, &argv);
    int num_procs, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 
    // Read cmd-line arguments and set parameters
    char **argv_avida = ParseArgs(argc, argv, universe_settings, argc_avida);

    // Load parameters and settings from meta config. 
    INIReader reader("metaconfig.ini"); // Filen ligger i root-dir för att komma med i git men ska ligga i work för att hittas
    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'metaconfig.ini'\n";
        return 1;
    }

    // Genetic parameters
    double gene_min = reader.GetInteger("genetic", "gene_min", -1);
    double gene_max = reader.GetInteger("genetic", "gene_max", 1);
    bool binary_genes = reader.GetBoolean("genetic", "binary_genes", false);
    double tournament_probability = reader.GetReal("genetic", "tournament_probability", 0.8);
    double crossover_probability = reader.GetReal("genetic", "crossover_probability", 0.3);
    double mutation_probability_constant = reader.GetReal("genetic", "mutation_probability_constant", 3);
    double mutation_decay = reader.GetReal("genetic", "mutation_decay", 0.95);
    double min_mutation_constant = reader.GetReal("genetic", "mutation_decay", 0.5);
    double creep_probability = reader.GetReal("genetic", "mutation_decay", 0.95);
    double creep_decay = reader.GetReal("genetic", "mutation_decay", 0.98);

    // Control settings
    std::vector<double> ref_bonus = Str2DoubleVector(reader.Get("control", "ref_bonus", "1 1 2 2 3 3 4 4 5"));
    double strategy_min = reader.GetReal("control", "strategy_min", -10);
    double strategy_max = reader.GetReal("control", "strategy_max", 10);
    std::string discrete_strategy = reader.Get("control", "discrete_strategy", "real");
    std::string Phi0_function = reader.Get("control", "controller_fitness", "standard");
    double Phi0_penalty_factor = reader.GetReal("control", "Phi0_penalty_factor", 0);
    std::string dangerous_operations_string = reader.Get("control", "dangerous_operations", "-1");
    std::vector<int> dangerous_operations = Str2IntVector(reader.Get("control", "dangerous_operations", "-1"));
    double task_perform_penalty_threshold = reader.GetReal("control", "task_perform_penalty_threshold", 0.05);
    int intervention_frequency = reader.GetInteger("control", "intervention_frequency", 100);
    int num_hidden_nodes = reader.GetInteger("control", "num_hidden_nodes", 10);

    // Iteration limits
    int num_worlds = reader.GetInteger("iterations", "num_worlds", 20);
    int num_meta_generations = reader.GetInteger("iterations", "num_meta_generations", 5);
    int num_updates = reader.GetInteger("iterations", "num_updates", 100);

    // General settings
    bool save_updates = reader.GetBoolean("general", "save_updates", true);
    std::string save_folder = reader.Get("general", "save_folder_name", "run");
    std::string random_meta_seed = reader.Get("general", "random_meta_seed", "imeta");

    // Overwrite configfile params with cmdline arguments
    num_worlds = (universe_settings[0] != -1) ? universe_settings[0] : num_worlds;
    num_meta_generations = (universe_settings[1] != -1) ? universe_settings[1] : num_meta_generations;
    num_updates = (universe_settings[2] != -1) ? universe_settings[2] : num_updates;
    universe_settings[0] = num_worlds;
    universe_settings[1] = num_meta_generations;
    universe_settings[2] = num_updates;

    // Derived params
    int num_tasks = ref_bonus.size();
    int num_input_nodes = num_tasks + 2; // bonusvektorn + u + phi som controller input
    int chromosome_length = num_hidden_nodes*(1 + num_input_nodes) + num_tasks*(1 + num_hidden_nodes);
    double mutation_probability = mutation_probability_constant/chromosome_length;
    double creep_rate = (gene_max-gene_min)/3.0;
    double min_creep = (gene_max-gene_min)/25.0;
    if (binary_genes) creep_probability = 1;

    // MPI params
    int root = 0;
    int limit = num_worlds/num_procs;

    // Initialise starting conditions
    std::vector<std::vector<double> > controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max, binary_genes);
    FileSystem fs = FileSystem(0);

    if (rank == root)  {
        std::cout << "Running with " << num_procs << " processes, " << num_worlds << " worlds, " << num_meta_generations << " meta generations, " << num_updates << " updates" << std::endl;
    
        // Save settings
        fs.SaveSettings(num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep, ref_bonus.data(), num_tasks, Phi0_function.c_str(), Phi0_penalty_factor, dangerous_operations_string.c_str(), task_perform_penalty_threshold, random_meta_seed.c_str());
        fs.InitMetaData(chromosome_length);
    }
    
    // Initialise Avida
    Avida::Initialize();
    Apto::Map<Apto::String, Apto::String> defs;
    cAvidaConfig* cfg = new cAvidaConfig();
    Avida::Util::ProcessCmdLineArgs(argc_avida, argv_avida, cfg, defs);

    // Timing
    auto start_time = std::chrono::high_resolution_clock::now(); 
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(end_time - start_time); 

    // Main loop over meta generations
    for (size_t imeta = 0; imeta < num_meta_generations; imeta++)   {

        std::vector<double> current_fitness(num_worlds, 0);
        // std::vector< std::vector<double> > current_bonus(num_worlds, std::vector<double>(num_tasks, 0));
        if (random_meta_seed == "0") cfg->RANDOM_SEED.Set(0);
        else cfg->RANDOM_SEED.Set(imeta);

        //if (rank == root)
        fs.InitUpdateDirectory(imeta);

        // Receive controllers
        for (int i=0; i<num_worlds; i++) {
            for (int j=0; j<chromosome_length; j++) {
                MPI_Bcast(&controllers[i][j], 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
            }
        }

        // Find our working interval
        int rank_num = rank+1;
        int end = rank_num*limit-1, start = rank_num*limit-limit;
            
        // Run avida for chosen worlds
        for (int iworld=start; iworld<=end; iworld++)   {

            // Initialise world
            Avida::World* new_world = new Avida::World();
            cUserFeedback feedback;

            // Set up controller 
            cController* controller = new cController(Phi0_function, ref_bonus, controllers[iworld], Phi0_penalty_factor, dangerous_operations, task_perform_penalty_threshold, intervention_frequency, strategy_min, strategy_max, discrete_strategy);
            controller->SetWeights(DecodeChromosome(controllers[iworld], num_tasks));

            // Set up world
            cWorld* world = new cWorld(cfg, cString(Apto::FileSystem::GetCWD()), controller);
            world->setup(new_world, &feedback, &defs);
            world->SetVerbosity(0);

            // Run simulation and compute fitness
            Avida2MetaDriver* driver = new Avida2MetaDriver(world, new_world);
            bool save = (iworld == 0) ? true : false;
            current_fitness[iworld] = driver->Run(num_updates, fs, save, iworld);
            // current_bonus[iworld] = driver->GetCurrentStrategy();

            // Clean up
            delete driver;
            delete controller;
            delete world;
            
        }

        // Send fitness to root process
        MPI_Send(&current_fitness[0], num_worlds, MPI_DOUBLE, root, 0, MPI_COMM_WORLD);
        // for (size_t i=0; i<num_worlds; i++) {
        //     std::vector<double> bonus_buffer = current_bonus[i];
        //     MPI_Send(&bonus_buffer[0], num_tasks, MPI_DOUBLE, root, 1, MPI_COMM_WORLD);
        // }

        if (rank == root)    {

            // std::vector<std::vector<std::vector<double>>> bonuses = std::vector<std::vector<std::vector<double>>>(num_procs, std::vector<std::vector<double>>(num_worlds, std::vector<double>(num_tasks)));

            std::vector<std::vector<double> > fitnesses = std::vector<std::vector<double> >(num_procs, std::vector<double>(num_worlds));
            std::vector<double> fitness_buffer(num_worlds);

            // Receive all fitness scores and bonuses
            for (int i=0; i<num_procs; i++) {
                MPI_Recv(&fitness_buffer[0], num_worlds, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                // std::vector<double> bonus_buffer(num_tasks);                
                for (int j = 0; j < num_worlds; j++)    {
                    fitnesses[i][j] = fitness_buffer[j];

                    // MPI_Recv(&bonus_buffer[0], num_tasks, MPI_DOUBLE, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    // for (int k=0; k<num_tasks; k++) {
                    //     bonuses[i][j][k] = bonus_buffer[k];
                    // }
                }
            }
            // Sum up fitness
            for (size_t i=0; i<num_worlds; i++) {
                double colsum = 0;
                for (size_t j=0; j<num_procs; j++) {
                    colsum += fitnesses[j][i];
                }
                current_fitness[i] = colsum;
            }

            // // Sum up bonuses
            // for (size_t i=0; i<num_worlds; i++) {
            //     std::vector< std::vector<double> > bonus_matrix = std::vector< std::vector<double> >(num_worlds, std::vector<double>(num_tasks, 0));

            //     for (size_t k=0; k<num_tasks; k++) {
            //         double bonus_sum = 0;
            //         for (size_t j=0; j<num_procs; j++) {
            //             bonus_sum += bonuses[j][i][k];
            //         }
            //         bonus_matrix[i][k] = bonus_sum;
            //     }
            // }
      
        
            // Update best results so far
            int imax = std::max_element(current_fitness.begin(),current_fitness.end()) - current_fitness.begin();
            std::vector<double> best_chromosome = controllers[imax];
            double max_fitness = current_fitness[imax];
            // std::vector<double> best_bonus = current_bonus[imax];

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
                controllers[iworld] = Mutate(chromosome, mutation_probability, creep_rate, creep_probability, gene_min, gene_max, binary_genes);
            }

            //Elitism
            controllers[0] = best_chromosome;
            
            // Print progress
            end_time = std::chrono::high_resolution_clock::now(); 
            duration = std::chrono::duration_cast<std::chrono::minutes>(end_time - start_time);

            cout << "Meta Generation: " << imeta
                 << ", Fitness: " << max_fitness 
                //  << ", Best chromosome: [";
                // for (size_t task = 0; task < chromosome_length; task++)
                //     cout << best_chromosome[task] << ", ";
                << ", Elapsed: " << duration.count() << " minutes" << endl;

            // Save training data to file
            fs.SaveMetaData(chromosome_length, imeta, max_fitness, best_chromosome);

            // Save chromosomes to file (to be able to continue at last imeta)
            fs.SaveChromosomes(controllers, num_worlds, chromosome_length);

        }

    }

    if (rank == root)  {
        std::cout << "simulation finished" << std::endl;  
    }
    
    // Clean up
    delete[] argv_avida;
    delete cfg;

    MPI_Finalize();

}

