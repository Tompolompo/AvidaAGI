// cController.h
#ifndef cController_h // include guard
#define cController_h

//genome
#include "avida/core/Genome.h"

namespace Controller{
    class cController{
    public:
        int mc_set_val;
        int mc_parent_id;

        cController();
        void speak();
        void set_val(int value);
        void print_val();
        void set_parent_id(int parent_id);
        Avida::Genome controll_genome(Avida::Genome* genome);

    };
}


#endif