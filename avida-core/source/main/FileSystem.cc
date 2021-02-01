#include "FileSystem.h" 
#include <bits/stdc++.h> 
#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <ctime>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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
            cerr << "Error :  " << strerror(errno) << endl; 
        }
    
        else{
            //cout << "Directory created with name: " << root_dir << endl;
            //strcpy(root_dir, root_dir);
            cout << root_dir << " saved as root directory" << endl;
        }
        /*
        strcpy (current_meta_dir, "./");
        strcat (current_meta_dir, root_dir);
        strcat (current_meta_dir, "/meta");
        if (mkdir(current_meta_dir, 0777) == -1) 
            cerr << "Error :  " << strerror(errno) << endl; */
  
    }
    else{
        //cout << "Directory already created: " << root_dir << endl;
    }
            
}
void FileSystem::SaveSettings(int num_worlds, int num_meta_generations, int num_updates, double tournament_probability, double crossover_probability, double mutation_probability,double mutation_probability_constant, double mutation_decay, double gene_min, double gene_max,  double creep_rate, double creep_probability, double creep_decay, std::vector<double> Phi_0, int chromosome_length){

    char settings_filename[80] = "./";
    strcat(settings_filename, root_dir);
    strcat(settings_filename, "/settings.csv");
    FILE *file_settings = fopen(settings_filename, "w");
    fprintf(file_settings, "N,M,I,tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, gene_min, gene_max, creep_rate, creep_probability, creep_decay");
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_settings, ",hatPhi_0[%d]", task);
    }
    fprintf(file_settings, "\n");
    fprintf(file_settings, "%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", num_worlds, num_meta_generations, num_updates, tournament_probability, crossover_probability, mutation_probability, mutation_probability_constant, mutation_decay, gene_min, gene_max,  creep_rate, creep_probability, creep_decay);
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_settings, ",%f", Phi_0[task]);
    }
    fprintf(file_settings, "\n");
    fclose(file_settings);
}

void FileSystem::InitMetaData(int chromosome_length){
    strcpy (meta_data_file, "./");
    strcat(meta_data_file, root_dir);
    strcat(meta_data_file, "/metarun.csv");
    FILE *file_meta_run = fopen(meta_data_file, "w");
    fprintf(file_meta_run, "m,max(Phi_0)");
    for (int task = 0; task < chromosome_length; task++){
      fprintf(file_meta_run, ",hatphi%d", task);
    }
    fprintf(file_meta_run, "\n");
    fclose(file_meta_run);
}

void FileSystem::SaveMetaData(int chromosome_length, int imeta, double current_max_fitness, std::vector<double> best_chromosome){
    strcpy (meta_data_file, "./");
    strcat(meta_data_file, root_dir);
    strcat(meta_data_file, "/metarun.csv");
    FILE *file_meta_run = fopen(meta_data_file, "a");
    fprintf(file_meta_run, "%d,%f", imeta, current_max_fitness);
    for (int task = 0; task < chromosome_length; task++){
        double l = best_chromosome[task];
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
        for (int task = 0; task < chromosome_length; task++){
            fprintf(file_chromosomes, "%f,", chromosomes[iworld][task]);

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
