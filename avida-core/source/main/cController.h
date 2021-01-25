// cController.h
#ifndef cController_h // include guard
#define cController_h

//genome
#include "avida/core/Genome.h"

namespace Controller{
    class cController{
    public:
        cController();
        double Phi_0[9];
        double m_chromosome[9];
        void SetChromosome(double chromosome[], int len);
        Avida::Genome controll_genome(Avida::Genome* genome);

    };
}

#endif