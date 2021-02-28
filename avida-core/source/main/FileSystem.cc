#include "FileSystem.h" 
#include <bits/stdc++.h> 
#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <ctime>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

/* Parse cmd-line arguments, extract the AGI-params and pass on the Avida params */
char **ParseArgs(int argc, char **argv, int *universe_settings, int &argc_avida)    {

    int opt; 
    while((opt = getopt(argc, argv, "n:m:u:i:")) != -1)
    {  
        switch(opt) {   
            case 'n':
                universe_settings[0] = atoi(optarg); // must be even number
                break;  
            case 'm':  
                universe_settings[1] = atoi(optarg);
                break; 
            case 'u':  
                universe_settings[2] = atoi(optarg);
                break; 
            case 'i':  
                universe_settings[3] = atoi(optarg);
                break;
            case '?':  
                printf("'%c': Not a valid option\n",optopt); 
                abort();
        }
    }
    argc_avida = argc-optind+1;
    char** argv_new = new char*[argc_avida];
    argv_new[0] = argv[0];
    for (int index = optind, i = 1; index < argc; index++, i++)
        argv_new[i] = argv[index];

    return argv_new;        
}

std::vector<int> Str2IntVector(std::string input) 
{
    std::istringstream is( input );
    std::vector<int> output( ( std::istream_iterator<int>( is ) ), ( std::istream_iterator<int>() ) );   
    
    return output;
}
std::vector<double> Str2DoubleVector(std::string input) 
{
    std::istringstream is( input );
    std::vector<double> output( ( std::istream_iterator<double>( is ) ), ( std::istream_iterator<double>() ) );   
    
    return output;
}

FileSystem::FileSystem(int imeta)
{
    //cout << " File system Initialized " << endl;
    // Get date and time as string
    /*
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(root_dir,sizeof(root_dir),"%d-%m-%Y_%H-%M-%S",timeinfo);
    */

    if (imeta == 0){
        // Creating a directory 
        if (mkdir(root_dir, 0777) == -1) {
            //cerr << "message :  " << strerror(errno) << endl; 
        }
    
        else{
            //cout << "Directory created with name: " << root_dir << endl;
            //strcpy(root_dir, root_dir);
            //cout << root_dir << " saved as root directory" << endl;
        }
        
        strcpy (current_meta_dir, "./");
        strcat (current_meta_dir, root_dir);
        strcat (current_meta_dir, "/meta");
        if (mkdir(current_meta_dir, 0777) == -1){
            //cerr << "message :  " << strerror(errno) << endl; 
        }
  
    }
    else{
        strcpy (current_meta_dir, "./");
        strcat (current_meta_dir, root_dir);
        strcat (current_meta_dir, "/meta");
    }
            
}

void FileSystem::SaveSettings(int num_worlds, int num_meta_generations, int num_updates, double tournament_probability, double crossover_probability, double mutation_probability,double mutation_probability_constant, double mutation_decay, double min_mutation_constant, double gene_min, double gene_max,  double creep_rate, double creep_probability, double creep_decay, double min_creep, double* Phi_0, int num_tasks, const char* Phi0_function, double Phi0_penalty_factor, const char* dangerous_operations, double task_perform_penalty_threshold, const char* random_meta_seed){

    char settings_filename[80] = "./";
    strcat(settings_filename, root_dir);
    strcat(settings_filename, "/settings.csv");
    FILE *file_settings = fopen(settings_filename, "w");
    fprintf(file_settings, "N,M,U, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max, creep_rate, creep_probability, creep_decay, min_creep");
    for (int task = 0; task < num_tasks; task++)
      fprintf(file_settings, ",hatPhi_0[%d]", task);
    fprintf(file_settings, ",Phi0_function,Phi0_penalty_factor,dangerous_operations,task_perform_penalty_threshold,random_meta_seed");
    fprintf(file_settings, "\n");
    fprintf(file_settings, "%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep);
    for (int task = 0; task < num_tasks; task++)
      fprintf(file_settings, ",%f", Phi_0[task]);
    fprintf(file_settings, ",%s,%.12f,%s,%9f,%s", Phi0_function, Phi0_penalty_factor, dangerous_operations, task_perform_penalty_threshold, random_meta_seed);
    fprintf(file_settings, "\n");
    fclose(file_settings);
}

void FileSystem::SaveSettings(int num_worlds, int num_meta_generations, int num_updates, double tournament_probability, double crossover_probability, double mutation_probability,double mutation_probability_constant, double mutation_decay, double min_mutation_constant, int gene_min, int gene_max,  double creep_rate, double creep_probability, double creep_decay, double min_creep, double* Phi_0, int num_tasks, const char* Phi0_function, double Phi0_penalty_factor, const char* dangerous_operations, double task_perform_penalty_threshold, const char* random_meta_seed){


    char settings_filename[80] = "./";
    strcat(settings_filename, root_dir);
    strcat(settings_filename, "/settings.csv");
    FILE *file_settings = fopen(settings_filename, "w");
    fprintf(file_settings, "N,M,U, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max, creep_rate, creep_probability, creep_decay, min_creep");
    for (int task = 0; task < num_tasks; task++)
      fprintf(file_settings, ",hatPhi_0[%d]", task);
    fprintf(file_settings, ",Phi0_function,Phi0_penalty_factor,dangerous_operations,task_perform_penalty_threshold,random_meta_seed");
    fprintf(file_settings, "\n");
    fprintf(file_settings, "%d,%d,%d,%f,%f,%f,%f,%f,%f,%d,%d,%f,%f,%f,%f", num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, min_mutation_constant, gene_min, gene_max,  creep_rate, creep_probability, creep_decay, min_creep);
    for (int task = 0; task < num_tasks; task++)
      fprintf(file_settings, ",%f", Phi_0[task]);
    fprintf(file_settings, ",%s,%.12f,%s,%9f,%s", Phi0_function, Phi0_penalty_factor, dangerous_operations, task_perform_penalty_threshold, random_meta_seed);
    fprintf(file_settings, "\n");
    fclose(file_settings);
}

void FileSystem::InitMetaData(int num_tasks){
    strcpy (meta_data_file, "./");
    strcat(meta_data_file, root_dir);
    strcat(meta_data_file, "/metarun.csv");
    FILE *file_meta_run = fopen(meta_data_file, "w");
    fprintf(file_meta_run, "m,max(Phi_0)");
    for (int task = 0; task < num_tasks; task++){
      fprintf(file_meta_run, ",hatphi%d", task);
    }
    fprintf(file_meta_run, "\n");
    fclose(file_meta_run);
}

void FileSystem::SaveMetaData(int num_tasks, int imeta, double current_max_fitness, std::vector<double> bonus){
    strcpy (meta_data_file, "./");
    strcat(meta_data_file, root_dir);
    strcat(meta_data_file, "/metarun.csv");
    FILE *file_meta_run = fopen(meta_data_file, "a");
    fprintf(file_meta_run, "%d,%f", imeta, current_max_fitness);
    for (int task = 0; task < num_tasks; task++){
        double l = bonus[task];
        fprintf(file_meta_run, ",%f", l);
    }
    fprintf(file_meta_run, "\n");
    fclose(file_meta_run);
}

void FileSystem::SaveChromosomes(std::vector<std::vector<double> > chromosomes, int num_worlds, int chromosome_length){

    char chromosomes_file[80] ="";
    strcat (chromosomes_file, root_dir);
    strcat (chromosomes_file, "/chromosomes.csv");
    
    FILE *file_chromosomes = fopen(chromosomes_file, "w");
    for (int iworld=0; iworld < num_worlds; iworld++){
        for (int gene = 0; gene < chromosome_length; gene++){
            fprintf(file_chromosomes, "%f,", chromosomes[iworld][gene]);

        }
    }
    fclose(file_chromosomes);
}

std::vector<std::vector<double> > FileSystem::ReadChromosomes(double num_worlds, double chromosome_length)
{
    /*std::string fileName = "./";
    strcat(fileName, root_dir);
    strcat(fileName, "/chromosomes.csv");*/
    char chromosomes_file[80] ="";
    strcat (chromosomes_file, root_dir);
    strcat (chromosomes_file, "/chromosomes.csv");

    std::vector<std::string> vecOfStr;
    std::ifstream in(chromosomes_file);
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str, ',')){
        if(str.size() > 0)
            vecOfStr.push_back(str);
    }

    std::vector<std::vector<double> > chromosomes = std::vector<std::vector<double> >(num_worlds, std::vector<double>(chromosome_length, 0));
    int istr = 0;
    for (int i=0; i<num_worlds; i++){
        for (int igene=0; igene<chromosome_length; igene++){
            chromosomes[i][igene] = std::stod(vecOfStr[istr]);
            istr+=1;
        }
    }
    
    return chromosomes;
}

void FileSystem::InitUpdateDirectory(int meta_generation){
    strcpy (current_meta_dir, "./");
    strcat (current_meta_dir, root_dir);
    strcat (current_meta_dir, "/meta");

    std::string str = current_meta_dir;
    str +="/M";
    str += to_string(meta_generation);
    strcpy(current_meta_dir, str.c_str());
    if (mkdir(current_meta_dir, 0777) == -1){
        //cerr << "message :  " << strerror(errno) << endl; 
    }
    else{
        //cout << "Directory created with name: " << current_meta_dir << endl;
    }
}

void FileSystem::InitUpdateData(int n_world, int num_tasks){
    std::string str = current_meta_dir;
    str +="/N";
    str += to_string(n_world);
    str += ".csv";
    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());
    FILE *file_N = fopen(char_array, "w");
    fprintf(file_N, "UD,Gen,phi_i,phi_0,orgs");
    for (int task = 0; task < num_tasks; task++){
        fprintf(file_N, ",task%d", task);
    }
    fprintf(file_N, "\n");
    fclose(file_N);

}

void FileSystem::SaveUpdateData(int n_world, int update, double generation, double phi_i, double phi_0, int n_orgs, std::vector<int> tasks, int num_tasks){
    std::string str = current_meta_dir;
    str +="/N";
    str += to_string(n_world);
    str += ".csv";
    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());
    FILE *file_N = fopen(char_array, "a");
    fprintf(file_N, "%d,%f,%f,%f,%d", update, generation, phi_i, phi_0, n_orgs);
    for (int task = 0; task < num_tasks; task++){ 
      fprintf(file_N, ",%d", tasks[task]);
    }
    fprintf(file_N, "\n");
    fclose(file_N);
}