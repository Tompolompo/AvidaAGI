// cController.h
#ifndef cController_h // include guard
#define cController_h

class cEnvironment;


// #include "avida/core/Genome.h"
#include <vector>
#include <Eigen/Dense>

class cController{
public:

    cController();
    cController(std::string Phi0_function, std::vector<double> ref_chromosome, std::vector<double> chromosome, double penalty_factor, std::vector<int> dangerous_operations, double task_perform_penalty_threshold, int intervention_frequency);

    // chromosome related
    std::vector<double> m_X0;
    std::vector<double> m_chromosome;
    int m_chromosome_length;
    std::string m_Phi0_function;

    // dangerous operations
    std::vector<int> m_task_performed_counter;
    std::vector<int> m_dangerous_operations;
    double m_penalty_factor;
    double m_task_perform_threshold;

    // controller strategy
    int m_intervention_frequency;



    // Accessor functions
    void SetPhi0Function(std::string func_name){ m_Phi0_function = func_name; }
    void SetChromosome(std::vector<double> chromosome){ m_chromosome = chromosome; }
    void SetRefChromosome(std::vector<double> chromosome){ m_X0 = chromosome; };

    void IncPerformedTask(int task_number);
    void ResetTaskCounter();
    
    // ANN controller
    std::vector<double> EvaluateAvida(std::vector<double> performed_task_fraction, int u, double phi);
    Eigen::MatrixXf sigmoid(Eigen::MatrixXf matrix);

    void PrintChromosome(int which);

    // Avida::Genome controll_genome(Avida::Genome* genome);

};

#endif