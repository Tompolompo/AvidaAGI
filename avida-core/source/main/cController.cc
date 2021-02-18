#include <iostream> 
#include "cController.h" // header in local directory

using namespace std;
using namespace Controller;

cController::cController() {
    // Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;
    // Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;
    // m_chromosome[0]=1;m_chromosome[1]=1;m_chromosome[2]=2;m_chromosome[3]=2;m_chromosome[4]=3;
    // m_chromosome[5]=3;m_chromosome[6]=4;m_chromosome[7]=4;m_chromosome[8]=5;
    // m_chromosome_length = 9;
}

void cController::SetChromosome(double chromosome[], int len){
    m_chromosome_length = len;
    for (int i=0; i<len; i++){
        m_chromosome[i]=chromosome[i];
    }
}

void cController::SetRefChromosome(double chromosome[], int len){
    for (int i=0; i<len; i++){
        Phi_0[i]=chromosome[i];
    }
}

void cController::PrintChromosome(int which) {
    for (int i=0; i<m_chromosome_length; i++){
        if (which == 1) {
            std::cout << Phi_0[i] << " ";
        }
        else    {
            std::cout << m_chromosome[i] << " ";
        }
        
    }
    std::cout << std::endl;
}



Avida::Genome cController::controll_genome(Avida::Genome* old_genome){
    /*
    Apto::String genome_string = old_genome->AsString();
    //cout << genome_string << endl;
    Apto::String sub_string_start = genome_string.Substring(0, 42);
    Apto::String sub_string_end = genome_string.Substring(42, -1);
    //Apto::String insert = "c";
    //Apto::String updated_genome = sub_string_start + insert + sub_string_end;
    Apto::String updated_genome = sub_string_start + sub_string_end;
    //cout << updated_genome << endl;
    Avida::Genome new_genome = Avida::Genome(updated_genome);
    */
    return *old_genome;
}







        //~cController();
/*
    void method()
    {   
        std::cout << std::endl;
        std::cout << "********************************" << std::endl;
        std::cout << "This is you controller speaking!" << std::endl;
        
        /*
        cout << " I have information about the population: " << endl;
        double generation = m_stats->GetGeneration();
        int num_creatures = m_stats->GetNumCreatures();
        double average_merit = m_stats->GetAveMerit();
        

        cout << "Generation= " << generation << endl;
        cout << "Number of creatures= " << num_creatures << endl;
        cout << "Average merit= " << average_merit << endl;
        cout << "********************************" << endl;
        cout << endl;
    }
        */


