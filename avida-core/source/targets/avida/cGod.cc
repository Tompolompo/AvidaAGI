#include "cGod.h" // header in local directory
#include <iostream> // header in standard library

using namespace std;

cGod::cGod(int universe_settings[4]){
    /* (0) NOT (1) NAND (2) AND (3) ORN (4) OR (5) AND (6) NOR (7) XOR (8) EQU  */
    
    m_number_of_worlds = universe_settings[0];
    m_meta_generations = universe_settings[1];
    m_meta_generation_step_size = universe_settings[2];
    m_dangerous_op = universe_settings[3];
}

void cGod::speak()
{
    cout << "This is God speaking!" << endl;
}