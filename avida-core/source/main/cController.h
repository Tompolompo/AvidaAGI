// cController.h
#ifndef cController_h // include guard
#define cController_h

class cEnvironment;


// #include "avida/core/Genome.h"
#include <vector>
#include <Eigen/Dense>

class cController{
public:

    cController(std::string Phi0_function, std::vector<double> ref_bonus, std::vector<double> chromosome, double penalty_factor, std::vector<int> dangerous_operations, double task_perform_penalty_threshold, int intervention_frequency, double strategy_min, double strategy_max, std::string discrete_strategy, std::string activation_method);

    // chromosome related
    std::vector<double> m_X0;
    std::vector<double> m_chromosome;
    int m_chromosome_length;
    std::vector<Eigen::MatrixXf> m_weight_matrices;

    // dangerous operations
    std::vector<int> m_task_performed_counter;
    std::vector<int> m_dangerous_operations;
    double m_penalty_factor;
    double m_task_perform_threshold;

    // controller strategy
    int m_intervention_frequency;
    std::string m_Phi0_function;
    int m_num_tasks;
    std::string m_activation_method;
    double m_strategy_min;
    double m_strategy_max;
    std::string m_discrete_strategy;



    // Accessor functions
    void SetPhi0Function(std::string func_name){ m_Phi0_function = func_name; }
    void SetChromosome(std::vector<double> chromosome){ m_chromosome = chromosome; }
    void SetRefChromosome(std::vector<double> chromosome){ m_X0 = chromosome; }
    void SetWeights(std::vector<Eigen::MatrixXf> weights){ m_weight_matrices = weights; }

    void IncPerformedTask(int task_number);
    void ResetTaskCounter();
    
    // controller functions
    std::vector<double> EvaluateAvidaFas1(std::vector<double> performed_task_fraction, int u, double phi);
    std::vector<double> EvaluateAvidaANN(std::vector<double> performed_task_fraction, int delta_u, double delta_phi);
    Eigen::MatrixXf Activation(Eigen::MatrixXf matrix, std::string method);
    std::vector<double> ScaleVector(std::vector<double> arr, double low, double high);
    std::vector<double> DiscretiseVector(std::vector<double> arr, std::string method);

    // Diagnostics
    void PrintArray(std::vector<double> array);

    // Avida::Genome controll_genome(Avida::Genome* genome);

};

#endif