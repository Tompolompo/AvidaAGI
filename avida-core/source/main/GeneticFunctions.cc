#include <iostream>
#include <random>
#include <algorithm>
#include <unistd.h>

std::random_device rd;
std::mt19937 e(rd());
static std::uniform_real_distribution<> dis(0, 1);

/* Generate a uniform random real number */
double RandomNumber(char dist, int min, int max)
{
    double r = dis(e);

    if (dist == 'r')    {
        return r * (max - min) + min;
    }
    if (dist == 'i')    {
        return (int) (r * (max - min) + min);
    }
    else    {
        std::cout << "wrong distribution specified" << std::endl;
        return -1;
    }
}


/* Parse cmd-line arguments, extract the AGI-params and pass on the Avida params */
char **ParseArgs(int argc, char **argv, int *universe_settings, int &argc_avida)    {

    int opt; 
    while((opt = getopt(argc, argv, "n:m:u:d:")) != -1)
    {  
        switch(opt) {   
            case 'n':
                universe_settings[0] = atoi(optarg); // must be even number
                break;  
            case 'm':  
                universe_settings[1] = atoi(optarg);
                break; 
            case 'u':  
                universe_settings[2] = atoi(optarg);
                break; 
            case 'i':  
                universe_settings[3] = atoi(optarg);
                break;
            case '?':  
                printf("'%c': Not a valid option\n",optopt); 
                abort();
        }
    }
    argc_avida = argc-optind+1;
    char** argv_new = new char*[argc_avida];
    argv_new[0] = argv[0];
    for (int index = optind, i = 1; index < argc; index++, i++)
        argv_new[i] = argv[index];

    return argv_new;        
}

/* Generates a population of chromosomes that contain the genomes for the controllers */
std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, double gene_min, double gene_max)
{
    // Initialize the array of chromosomes
    std::vector<std::vector<double> > population = std::vector<std::vector<double> >(num_worlds, std::vector<double>(chromosome_length, 0));

    // Generation of gene values
    for (int i = 0; i < population.size(); i++)
    {
        for (int j = 0; j < population[i].size(); j++)
        {
            // Random gene value generation
            population[i][j] = RandomNumber('r', gene_min, gene_max);
            // population[i][j] = 1 + i*j;
        }    
    }
    //std::cout << "Initial controller population generated" << std::endl;
    // for (size_t i = 0; i < population.size(); i++)
    // {
    //     for (size_t j = 0; j < population[i].size(); j++)
    //     {
    //         cout << population[i][j] << " ";
    //     }    
    //     cout << endl;
    // }

    return population;
}

/* Evaluates the fitness of a controller */
double EvaluateController(double *chromosome, int length)   {

    double sum = 0;
    for (size_t i=0; i<length; i++) {
        sum += chromosome[i];
    }
    return sum;
}

/* Compute tournament selection indices (with replacement) using the population fitness */
size_t TournamentSelect(std::vector<double> fitness, double tournament_probability)   {

    int population_size = fitness.size();
    int ix1 = RandomNumber('i', 0, population_size-1);
    int ix2 = RandomNumber('i', 0, population_size-1);
    int selected;
    
    int r = RandomNumber('r', 0, 1);
    if (r < tournament_probability) {
        if (fitness[ix1] > fitness[ix2])    {
            selected = ix1;
        } else  {
            selected = ix2;
        }
    } else  {
        if (fitness[ix1] > fitness[ix2])    {
            selected = ix2;
        } else  {
            selected = ix1;
        }
    }

    return selected;
}

/* Performs sexual reproduction by crossing two chromosomes with eachother and returning the children */
std::vector<std::vector<double> > Cross(std::vector<double> chromosome1, std::vector<double> chromosome2)   {
    int chromosome_length = chromosome1.size();
    size_t cross_point = RandomNumber('i', 0, chromosome_length-1);
    int temp;
    std::vector<double> new_chromosome1 = chromosome1;
    std::vector<double> new_chromosome2 = chromosome2;

    for (size_t i=cross_point; i<chromosome_length; i++)  {
            new_chromosome1[i] = chromosome2[i];
            new_chromosome2[i] = chromosome1[i];
        }

    std::vector<std::vector<double> > chromosomes = std::vector<std::vector<double> >(2, std::vector<double>(chromosome_length, 0));
    chromosomes[0] = new_chromosome1;
    chromosomes[1] = new_chromosome2;
    return chromosomes;
}

/* Mutates each gene in a chromosome with a certain probability and returns the mutated chromosome */
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, double gene_min, double gene_max) {
    int chromosome_length = chromosome.size();
    double x=0; 
    double r;
    for (size_t i=0; i<chromosome_length; i++) {
        r = RandomNumber('r', 0, 1);
        if ( r < mutation_probability) {
            if (RandomNumber('r', 0, 1) < creep_probability) {
                chromosome[i] += - creep_rate/2 + creep_rate*r;

                if (chromosome[i] > gene_max){
                    chromosome[i]=gene_max;
                }
                else if (chromosome[i] < gene_min){
                    chromosome[i]=gene_min;
                }
            }
            else{
                chromosome[i] = RandomNumber('r', gene_min, gene_max);
            } 
        }
    }

    return chromosome;
}

