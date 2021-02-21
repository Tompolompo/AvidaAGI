// cController.h
#ifndef cController_h // include guard
#define cController_h

//genome
#include "avida/core/Genome.h"
#include <vector>

class cController{
public:
    cController();
    cController(std::string Phi0_function, int chromosome_length);

    std::vector<double> m_X0;
    std::vector<double> m_chromosome;
    int m_chromosome_length;
    std::string m_Phi0_function;

    void SetPhi0Function(std::string func_name){ m_Phi0_function = func_name; }
    void SetChromosome( std::vector<double> chromosome){ m_chromosome = chromosome; }
    void SetRefChromosome( std::vector<double> chromosome){ m_X0 = chromosome; };

    void PrintChromosome(int which);

    Avida::Genome controll_genome(Avida::Genome* genome);

};

#endif