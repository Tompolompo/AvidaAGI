#ifndef FILESYSTEM_H // include guard
#define FILESYSTEM_H

#include <string>
#include <vector>

// Read and parse program arguments and return avid aarguments
char **ParseArgs(int argc, char **argv, int *universe_settings, int &argc_avida);

// Convert string of integers to vector
std::vector<int> Str2IntVector(std::string input);

// Convert string of doubles to vector
std::vector<double> Str2DoubleVector(std::string input);

class FileSystem{
    public:
        char buffer[80];
        char root_dir[80]="./data/AGIdata/run";
        char current_meta_dir[80];
        char meta_data_file[80];
        char population_folder[80];

        FileSystem(int imeta);

        std::vector<std::vector<double> > ReadChromosomes(double num_worlds, double chromosome_length);
        void SaveChromosomes(std::vector<std::vector<double> > chromosomes, int num_worlds, int chromosome_length);

        // Save settings of simulaion to file in m_root_dir as "settings.csv"
        void SaveSettings(int num_worlds, int num_meta_generations, int num_updates, double tournament_probability, double crossover_probability, double mutation_probability,double mutation_probability_constant, double mutation_decay, double min_mutation_constant, double gene_min, double gene_max,  double creep_rate, double creep_probability, double creep_decay, double min_creep, double* ref_bonus, int num_tasks, int num_strategies, const char* Phi0_function, double Phi0_penalty_factor, const char* dangerous_operations, double task_perform_penalty_threshold, const char* random_meta_seed);
        
        void SaveSettings(int num_worlds, int num_meta_generations, int num_updates, double tournament_probability, double crossover_probability, double mutation_probability,double mutation_probability_constant, double mutation_decay, double min_mutation_constant, int gene_min, int gene_max,  double creep_rate, double creep_probability, double creep_decay, double min_creep, double* Phi_0, int num_tasks, const char* Phi0_function, double Phi0_penalty_factor, const char* dangerous_operations, double task_perform_penalty_threshold, const char* random_meta_seed);
        
        // Initialize file for saving data over the meta evolution: "metarun.csv"
        void InitMetaData(int chromosome_length);
        
        // save data for meta generations
        void SaveMetaData(int chromosome_length, int imeta, double current_max_fitness, std::vector<double> chromosome, int imax);

        // create folder "M[%meta_generation]"
        void InitUpdateDirectory(int meta_generation); //update current meta_dir

        // create file "N[%n_world].csv" for world
        void InitUpdateData(int n_world, int num_tasks, int strategy_length); 

        // Save data for updates
        void SaveUpdateData(int n_world, int update, double generation, double phi_i, double phi_0, int n_orgs, std::vector<int> tasks, int num_tasks, std::vector<double> strategy, std::vector<double> bonus_vector_mean, std::vector<double> bonus_vector_var);
        
        // save population
};

#endif