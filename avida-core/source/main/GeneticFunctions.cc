#include <iostream>
#include <random>
#include <algorithm>

/* Generate a uniform random real number */
double RandomNumber(char dist, int min, int max)
{
    std::random_device rd;
    std::mt19937 e(rd());

    if (dist == 'r')    {
        static std::uniform_real_distribution<> dis(min, max);
        return dis(e);
    }
    if (dist == 'i')    {
        static std::uniform_int_distribution<> dis(min, max);
        return dis(e);
    }
    else    {
        std::cout << "wrong distribution specified" << std::endl;
        return -1;
    }
}

/* Generates a population of chromosomes that contain the genomes for the controllers */
std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, int gene_min, int gene_max)
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
    std::cout << "Initial controller population generated" << std::endl;
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
    size_t cross_point = RandomNumber('i', 0, chromosome_length);
    int temp;
    std::vector<double> new_chromosome1 = chromosome1;
    std::vector<double> new_chromosome2 = chromosome2;

    for (size_t i=cross_point; i<chromosome_length; i++)  {
            new_chromosome1[i] = chromosome2[i];
            new_chromosome2[i] = chromosome1[i];
        }

    std::vector<std::vector<double> > chromosomes = std::vector<std::vector<double> >(2, std::vector<double>(chromosome_length, 0));
    chromosomes[0] = chromosome1;
    chromosomes[1] = chromosome2;
    return chromosomes;
}

/* Mutates each gene in a chromosome with a certain probability and returns the mutated chromosome */
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability) {
    int chromosome_length = chromosome.size();
    double min = *min_element(chromosome.begin(), chromosome.end());
    double max = *max_element(chromosome.begin(), chromosome.end());

    for (size_t i=0; i<chromosome_length; i++) {
        if (RandomNumber('r', 0, 1) < mutation_probability) {
            chromosome[i] = RandomNumber('r', min, max);
        }
    }

    return chromosome;
}

