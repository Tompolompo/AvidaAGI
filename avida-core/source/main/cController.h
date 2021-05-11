// cController.h
#ifndef cController_h // include guard
#define cController_h

class cEnvironment;


// #include "avida/core/Genome.h"
#include <vector>
#include <Eigen/Dense>

class cController{
public:

    cController(std::string Phi0_function, std::vector<double> ref_bonus, std::vector<double> strategy, int strategy_length, double penalty_factor, std::vector<int> dangerous_operations, double task_perform_penalty_threshold, int intervention_frequency, double strategy_min, double strategy_max, std::string discrete_strategy, std::string activation_method, int num_instructions, double instruction_bias, double instruction_noise, double max_task_val, double min_task_val, int num_classes, int n_starting_humans);

    // basic properties
    std::vector<double> m_ref_bonus;
    std::string m_Phi0_function;
    int m_num_tasks;
    std::vector<double> m_strategy;
    int m_strategy_length;
    double m_strategy_min;
    double m_strategy_max;
    std::string m_discrete_strategy;
    double m_ref_bonus_abs;
    int m_intervention_frequency;

    // dangerous operations
    std::vector<int> m_task_performed_counter;
    std::vector<int> m_dangerous_operations;
    double m_penalty_factor;
    double m_task_perform_threshold;

    // Fas2
    std::string m_activation_method;
    std::vector<Eigen::MatrixXf> m_weight_matrices;

    // Fas3
    int m_num_instructions;
    int m_num_classes;
    double m_instruction_bias;
    double m_instruction_noise;
    double m_max_task_val;
    double m_min_task_val;

    // Asimov
    int m_humans_alive;



    // Accessor functions
    void SetPhi0Function(std::string func_name){ m_Phi0_function = func_name; }
    void SetRefChromosome(std::vector<double> chromosome){ m_ref_bonus = chromosome; }
    void SetWeights(std::vector<Eigen::MatrixXf> weights){ m_weight_matrices = weights; }

    void IncPerformedTask(int task_number);
    void ResetTaskCounter();
    
    // controller functions
    std::vector<double> EvaluateAvidaFas1(std::vector<double> performed_task_fraction, int u, double phi);
    std::vector<double> EvaluateAvidaFas3(std::vector<double> performed_task_fraction, double delta_u, double phi);
    std::vector<double> EvaluateAvida(std::vector<double> performed_task_fraction, double delta_u, double delta_phi);
    std::vector<double> EvaluateAvidaFas5(std::vector<double> performed_task_fraction, double delta_u, double delta_phi);
    std::vector<double> EvaluateAvidaANN(std::vector<double> performed_task_fraction, double delta_u, double delta_phi);
    Eigen::MatrixXf Activation(Eigen::MatrixXf matrix, std::string method);
    std::vector<double> ScaleVector(std::vector<double> arr, double low, double high);
    std::vector<double> DiscretiseVector(std::vector<double> arr, std::string method);

    // Diagnostics
    void PrintArray(std::vector<double> array);

    // Avida::Genome controll_genome(Avida::Genome* genome);

};

#endif