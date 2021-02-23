#include <iostream> 
#include "cController.h" // header in local directory


cController::cController() 
{
    // Phi_0[0]=1;Phi_0[1]=1;Phi_0[2]=2;Phi_0[3]=2;Phi_0[4]=3;
    // Phi_0[5]=3;Phi_0[6]=4;Phi_0[7]=4;Phi_0[8]=5;
    // m_chromosome[0]=1;m_chromosome[1]=1;m_chromosome[2]=2;m_chromosome[3]=2;m_chromosome[4]=3;
    // m_chromosome[5]=3;m_chromosome[6]=4;m_chromosome[7]=4;m_chromosome[8]=5;
    // m_chromosome_length = 9;

}

cController::cController(std::string Phi0_function, int chromosome_length, double penalty_factor, std::vector<int> dangerous_operations, double task_perform_penalty_threshold)
{
    m_Phi0_function = Phi0_function;
    m_chromosome_length = chromosome_length;
    m_task_performed_counter = std::vector<int>(m_chromosome_length, 0);
    m_penalty_factor = penalty_factor;
    m_dangerous_operations = dangerous_operations;
    m_task_perform_threshold = task_perform_penalty_threshold;

}

// cController::cController(std::string Phi0_function, int chromosome_length)
// {
//     m_Phi0_function = Phi0_function;
//     m_chromosome_length = chromosome_length;
    

// }

void cController::PrintChromosome(int which) {
    for (int i=0; i<m_chromosome_length; i++){
        if (which == 1) {
            std::cout << m_X0[i] << " ";
        }
        else    {
            std::cout << m_chromosome[i] << " ";
        }
        
    }
    std::cout << std::endl;
}

void cController::IncPerformedTask(int task_number)
{
    if (task_number == __INT_MAX__) std::cout << "error: task_number is maxed out" << std::endl;
    m_task_performed_counter[task_number]++;
}

void cController::ResetTaskCounter()
{
    for (size_t k=0; k<m_task_performed_counter.size(); k++)
        m_task_performed_counter[k] = 0;
}


// Avida::Genome cController::controll_genome(Avida::Genome* old_genome){
//     /*
//     Apto::String genome_string = old_genome->AsString();
//     //cout << genome_string << endl;
//     Apto::String sub_string_start = genome_string.Substring(0, 42);
//     Apto::String sub_string_end = genome_string.Substring(42, -1);
//     //Apto::String insert = "c";
//     //Apto::String updated_genome = sub_string_start + insert + sub_string_end;
//     Apto::String updated_genome = sub_string_start + sub_string_end;
//     //cout << updated_genome << endl;
//     Avida::Genome new_genome = Avida::Genome(updated_genome);
//     */
//     return *old_genome;
// }







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


