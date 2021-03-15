#include <iostream> 
#include <Eigen/Dense>
#include "cController.h" // header in local directory


cController::cController(std::string Phi0_function, std::vector<double> ref_bonus, std::vector<double> chromosome, double penalty_factor, std::vector<int> dangerous_operations, double task_perform_penalty_threshold, int intervention_frequency, double strategy_min, double strategy_max, std::string discrete_strategy, std::string activation_method)
{
    m_Phi0_function = Phi0_function;
    m_chromosome_length = chromosome.size();
    m_chromosome = chromosome;
    m_X0 = ref_bonus;
    m_num_tasks = ref_bonus.size();
    m_task_performed_counter = std::vector<int>(m_num_tasks, 0);
    m_penalty_factor = penalty_factor;
    m_dangerous_operations = dangerous_operations;
    m_task_perform_threshold = task_perform_penalty_threshold;
    m_intervention_frequency = intervention_frequency;
    m_strategy_min = strategy_min;
    m_strategy_max = strategy_max;
    m_discrete_strategy = discrete_strategy;
    m_activation_method = activation_method;

}

void cController::PrintArray(std::vector<double> array) {
    for (int i=0; i<array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void cController::IncPerformedTask(int task_number)
{
    // if (task_number == __INT_MAX__) std::cout << "error: task_number is maxed out" << std::endl;
    m_task_performed_counter[task_number]++;
}

void cController::ResetTaskCounter()
{
    for (size_t k=0; k<m_task_performed_counter.size(); k++)
        m_task_performed_counter[k] = 0;
}


Eigen::MatrixXf cController::Activation(Eigen::MatrixXf matrix, std::string method)
{
    if (method == "tanh")   {
        for (size_t i=0; i<matrix.rows(); i++)   {
            for (size_t j=0; j<matrix.cols(); j++)   {
                //   double before = matrix(i,j);
                matrix(i,j) = tanh(matrix(i,j));
                //   std::cout << "before: " << before << ", after: " << matrix(i,j) << std::endl;
            }
        }
    }
    else if (method == "sigmoid")   {
        for (size_t i=0; i<matrix.rows(); i++)   {
            for (size_t j=0; j<matrix.cols(); j++)   {
                //   double before = matrix(i,j);
                matrix(i,j) = 1 / (1 + exp(-matrix(i,j)));
                //   std::cout << "before: " << before << ", after: " << matrix(i,j) << std::endl;
            }
        }

    }

  return matrix;
}

std::vector<double> cController::ScaleVector(std::vector<double> arr, double low, double high)
{
    if (m_activation_method == "sigmoid")   {
        // std::cout << ">=0" << std::endl;
        for (int i=0; i<arr.size(); i++)
            arr[i] = low + 2*high*arr[i];
    }
    else if (m_activation_method == "tanh") {
        // std::cout << "<0" << std::endl;
        for (int i=0; i<arr.size(); i++)
            arr[i] = high*arr[i];
    }

    return arr;
}


std::vector<double> cController::EvaluateAvidaANN(std::vector<double> performed_task_fraction, int delta_u, double delta_phi)
{
    int num_outputs = performed_task_fraction.size();
    int num_inputs = num_outputs + 2; 
    Eigen::MatrixXf input_layer(1, num_inputs + 1);

    for (int i=0; i<num_outputs; i++)
        input_layer(0,i) = performed_task_fraction[i];
    input_layer(0, num_inputs-3) = delta_u;
    input_layer(0, num_inputs-2) = delta_phi;
    input_layer(0, num_inputs-1) = 1;
    // std::cout << "input_layer: " << input_layer << std::endl;

    Eigen::MatrixXf middle_layer = input_layer*m_weight_matrices[0];
    // std::cout << "middle_layer = " << middle_layer << std::endl;
    middle_layer = Activation(middle_layer, m_activation_method);
    // std::cout << "middle_layer activated = " << middle_layer << std::endl;
    middle_layer.conservativeResize(Eigen::NoChange, middle_layer.cols()+1);
    // std::cout << "middle_layer new1 = " << middle_layer << std::endl;
    Eigen::VectorXf ones = Eigen::VectorXf::LinSpaced(middle_layer.cols(), 1, 1);
    // std::cout << "ones = " << ones << std::endl;
    // std::cout << "cols = " << middle_layer.cols()-1 << std::endl;
    // std::cout << "middle_layer(cols) = " << middle_layer(0, middle_layer.cols()-1) << std::endl;
    middle_layer(0, middle_layer.cols()-1) = 1;
    // std::cout << "middle_layer new2 = " << middle_layer << std::endl;

    Eigen::MatrixXf output_layer = middle_layer*m_weight_matrices[1];
    // std::cout << "output_layer = " << output_layer << std::endl;
    output_layer = Activation(output_layer, m_activation_method);
    // std::cout << "output_layer activated = " << output_layer << std::endl;

    std::vector<double> bonus(m_num_tasks, 1);
    float* flat_matrix = output_layer.data();
    // std::cout << "bonus: " << std::endl;
    for (size_t i=0; i<m_num_tasks; i++)    {
        bonus[i] = flat_matrix[i];
        // std::cout << bonus[i] << ", ";
    }
    // std::cout << std::endl;


    bonus = ScaleVector(bonus, m_strategy_min, m_strategy_max);
    if (m_discrete_strategy != "real")  {
        // bonus = DiscretiseVector(bonus, m_discrete_strategy);
        for (int i=0; i<bonus.size(); i++)
                bonus[i] = std::round(bonus[i]);
    }
        
    return bonus;
}


std::vector<double> cController::EvaluateAvidaFas1(std::vector<double> performed_task_fraction, int delta_u, double delta_phi)
{
    std::vector<double> bonus(m_num_tasks, 1);

    for (size_t i=0; i<m_num_tasks; i++)    {

        if (performed_task_fraction[i] > 0.5)
            bonus[i] -= 1;
        else
            bonus[i] += 1;
    }

    return bonus;

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


