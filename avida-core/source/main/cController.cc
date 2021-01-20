// cController.cc
#include <iostream> 
//#include <string>
#include "cController.h" // header in local directory
//#include "cStats.h"

//genome
#include "avida/core/Genome.h"

using namespace std;
using namespace Controller;
//using namespace Avida;

//void cController::init(Apto::SmartPtr<cStats, Apto::InternalRCObject> m_stats)

cController::cController() {
    //cout << "********************************" << endl;
    //cout << "***CONSTRUCTOR of Controller****" << endl;
    //cout << "********************************" << endl;
    int mc_set_val=0;
};

void cController::speak(){
    cout << "Controller speaking" << endl;
}

void cController::set_val(int set_value){
    mc_set_val = set_value;
}

void cController::print_val(){
    cout << "val = " << mc_set_val << endl;
}

void cController::set_parent_id(int parent_id){
    mc_parent_id = parent_id;
}

Avida::Genome cController::controll_genome(Avida::Genome* old_genome){
    Apto::String genome_string = old_genome->AsString();
    //cout << genome_string << endl;
    Apto::String sub_string_start = genome_string.Substring(0, 42);
    Apto::String sub_string_end = genome_string.Substring(42, -1);
    //Apto::String insert = "c";
    //Apto::String updated_genome = sub_string_start + insert + sub_string_end;
    Apto::String updated_genome = sub_string_start + sub_string_end;
    //cout << updated_genome << endl;
    Avida::Genome new_genome = Avida::Genome(updated_genome);
    return new_genome;
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


