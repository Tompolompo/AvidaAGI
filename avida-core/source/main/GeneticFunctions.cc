#include <iostream>
#include <random>
#include <algorithm>


std::random_device rd;
std::mt19937 e(rd());
static std::uniform_real_distribution<> dis_r(0, 1);
static std::uniform_real_distribution<> dis_i(0, 1);

/* Generate a uniform random real number */
double RandomNumber(double min, double max)
{
    return dis_r(e) * (max - min) + min;
}

int RandomNumber(int min, int max)
{
    return dis_i(e) * (max - min) + min;
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
            population[i][j] = RandomNumber(gene_min, gene_max);

        }    
    }
    return population;
}

// takes integers
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
            population[i][j] = RandomNumber(gene_min, gene_max);
        }
    }   
    return population;
}

/* Test function for fitness of a controller */
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
    int ix1 = RandomNumber( 0, population_size-1);
    int ix2 = RandomNumber( 0, population_size-1);
    int selected;
    
    int r = RandomNumber(0.0, 1.0);
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
    size_t cross_point = RandomNumber(0, chromosome_length-1);
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
        r = RandomNumber(0.0, 1.0);
        if ( r < mutation_probability) {
            if (RandomNumber(0.0, 1.0) < creep_probability) {
                chromosome[i] += - creep_rate/2 + creep_rate*r;

                if (chromosome[i] > gene_max){
                    chromosome[i]=gene_max;
                }
                else if (chromosome[i] < gene_min){
                    chromosome[i]=gene_min;
                }
            }
            else{
                chromosome[i] = RandomNumber(gene_min, gene_max);
            } 
        }
    }

    return chromosome;
}

// int
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, int gene_min, int gene_max) {
    int chromosome_length = chromosome.size();
    double x=0; 
    double r;
    for (size_t i=0; i<chromosome_length; i++) {
        r = RandomNumber(0.0, 1.0);
        if ( r < mutation_probability) {
            if (RandomNumber(0.0, 1.0) < creep_probability) {

                if (RandomNumber(0.0, 1.0) >0.5){
                    chromosome[i] += 1;
                }
                else{
                    chromosome[i] -= 1;
                }
                
                if (chromosome[i] > gene_max){
                    chromosome[i]=gene_max;
                }
                else if (chromosome[i] < gene_min){
                    chromosome[i]=gene_min;
                }
            }
            else{
                chromosome[i] = RandomNumber(gene_min, gene_max);
            } 
        }
    }

    return chromosome;
}
