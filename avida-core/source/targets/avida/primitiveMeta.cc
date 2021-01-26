#include <iostream>
#include <fstream>
#include <unistd.h>

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

using namespace std;

int main(int argc, char *argv[])  {


    // Parse cmd-line arguments
    int universe_settings[4];
    universe_settings[0] = str2int(argv[1]); // Number of worlds, even number
    universe_settings[1] = str2int(argv[2]); // N meta generations
    universe_settings[2] = str2int(argv[3]); // Number of updates
    universe_settings[3] = 9; // dangerous op

    char * argv_new[1];
    argv_new[0] = argv[0];
    argc = 1;


    // Genetic parameters
    int gene_min = -10; 
    int gene_max = 10;
    size_t num_worlds = universe_settings[0];
    size_t num_generations  = universe_settings[1];
    size_t num_updates = universe_settings[2];
    size_t chromosome_length = 10;
    double tournament_probability = 0.5;
    double crossover_probability = 0.5;
    double mutation_probability = 0.5;
    char filepath[25] = "output/testresults.data";

    // Initialise god, result arrays and starting conditions
    cGod* God = new cGod(universe_settings);
    God->speak();
    ofstream output(filepath);
    output << "Results of Avida meta evolution simulation" << endl;
    std::vector<double> best_fitness(num_generations, 0);
    double best_chromosome[chromosome_length];
    std::vector<double> current_fitness(num_worlds, 0);
    std::vector<std::vector<double> > controllers = InitialisePopulation(num_worlds, chromosome_length, gene_min, gene_max);

    // Initialise avida stuff
    Avida::Initialize(); // Initialize...
    // cout << Avida::Version::Banner() << endl; // print the banner and current version of Avida
    Apto::Map<Apto::String, Apto::String> defs; // define a map that maps an apto string to an apto string
    cAvidaConfig* cfg = new cAvidaConfig(); /* define our avida configuration file /new callar på constructor) can overridea config-filen osv. */
    Avida::Util::ProcessCmdLineArgs(argc, argv_new, cfg, defs); // sätter på settings som användaren gör i command line. typ sätt på analyze mode etc 
    cUserFeedback feedback; //visar varningsmedelanden osv till användaren

    cout << "Universe settings: " << num_worlds << " worlds, " << num_generations << " meta generations, " << num_updates << " updates, " << endl;
    cout << "Starting Meta evolution " << endl;

    // Main loop over meta generations
    for (size_t imeta = 0; imeta < num_generations; imeta++)   {

        // Run for each controller
        double current_max_fitness = 0;
        for (size_t iworld = 0; iworld < num_worlds; iworld++) {
            
            // Initialize world
            Avida::World *new_world = new Avida::World();
            cWorld *world = cWorld::Initialize(cfg, cString(Apto::FileSystem::GetCWD()), new_world, &feedback, &defs);

            // Load controller chromosome
            double *chromosome = controllers[iworld].data();
            world->m_ctx->m_controller.SetChromosome(chromosome, chromosome_length);
            world->setup(new_world, &feedback, &defs);
            // world->SetVerbosity(0);

            // Run avida simulation and evaluate controller
            Avida2MetaDriver driver = Avida2MetaDriver(world, new_world, God);

            driver.Run();
            current_fitness[iworld] = EvaluateController(chromosome, chromosome_length);

            // clean up
            driver.~Avida2MetaDriver();

            // Update best results so far
            if (current_fitness[iworld] >= current_max_fitness)  {
                current_max_fitness = current_fitness[iworld];
                std::copy(chromosome, chromosome+chromosome_length, best_chromosome);
            }
        }

        cout << "**** 4" << endl;
        // Check progress
        best_fitness[imeta] = current_max_fitness;
        if (imeta%1 == 0)  {
            cout << "Generation: " << imeta << ", Fitness: " << current_max_fitness << endl;
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
        for (size_t iworld = 0; iworld < num_worlds; iworld++) {
            std::vector<double> chromosome = new_controllers[iworld];
            controllers[iworld] = Mutate(chromosome, mutation_probability);
        }

        //Elitism
        std::vector<double> best(best_chromosome, best_chromosome + chromosome_length);
        controllers[0] = best;

    }

    // Store results
    output << "best_fitness:";
    for (const auto &e : best_fitness)  {
        output << e << ", ";
    }
    output << "\n";
    output << "best_chromosome:";
    for(size_t count=0; count<chromosome_length; count++)   {
        output << best_chromosome[count] << ", ";
    }
    output << "\n";   

    output.close();
    cout << "Results saved in: " << filepath << endl;


    // Plot results
    // std::vector<double> x {1,2,3,4,5,6};
    // std::vector<double> y {1,2,-3,4,-5,6};
    // matplotlibcpp::plot(x, y);
    // matplotlibcpp::show();

    return 0;
}

