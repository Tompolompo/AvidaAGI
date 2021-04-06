#include <iostream>
#include <random>
#include <algorithm>
#include <Eigen/Dense>


std::random_device rd;
std::mt19937 e(rd());
static std::uniform_real_distribution<> dis_r(0, 1);
static std::uniform_real_distribution<> dis_i(0, 1);

/* Generate a uniform random real number */
double RandomNumber(double min, double max)
{
    //std::cout << "(0) max " << max << ", min " << min << ", dis: " << dis_r(e) << std::endl;
    return dis_r(e) * (max - min) + min;
}

int RandomNumber(int min, int max)
{
    //std::cout << "max " << max << ", min " << min << ", dis: " << dis_i(e) << std::endl;
    return (int) (dis_i(e) * (max + 1 - min) + min);
}

bool in_population(std::vector<double> trial, std::vector<std::vector<double> > population , int pop_size){
    
    for (int n=0;n<pop_size;n++){
        if (trial == population[n]){
            return true;
        }
    }
    return false;
}

/* Generates a population of chromosomes that contain the genomes for the controllers */
std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, double gene_min, double gene_max, bool binary, bool meta_evo)
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
std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, int gene_min, int gene_max, bool binary, bool meta_evo)
{
    // Initialize the array of chromosomes
    std::vector<std::vector<double> > population = std::vector<std::vector<double> >(num_worlds, std::vector<double>(chromosome_length, 0));
    // Generation of gene values
    
    static std::uniform_int_distribution<> dis_init(gene_min, gene_max);
    if (meta_evo){
        for (int i = 0; i < population.size(); i++)
        {
            for (int j = 0; j < population[i].size(); j++)
            {
                // Random gene value generation
                if (binary){
                    if (RandomNumber(0.0,1.0) > 0.5){
                        population[i][j] = gene_max;
                    }
                    else{
                        population[i][j] = gene_min;
                    }
                }
                else{
                    population[i][j] = dis_init(e);
                }
                
            }
        }
    }
    else{
        int init_count = 0;
        for (int j = 0; j < population[0].size(); j++){
            if (binary){
                if (RandomNumber(0.0,1.0) > 0.5){
                    population[0][j] = gene_max;
                }
                else{
                    population[0][j] = gene_min;
                }
            }
            else{
                population[0][j] = dis_init(e);
            }
        }

        for (int i = 1; i < population.size(); i++){
            
            for (int j = 0; j < population[i].size(); j++){
                if (binary){
                    if (RandomNumber(0.0,1.0) > 0.5){
                        population[i][j] = gene_max;
                    }
                    else{
                        population[i][j] = gene_min;
                    }
                }
                else{
                    population[i][j] = dis_init(e);
                }
            }
 
            while (in_population(population[i], population, i)){
                if (init_count > 10000000){
                    std::cout << "Took too long to initialize population. check if num worlds larger than possible permutations. " << std::endl;
                    return population;
                }
                init_count += 1;
                for (int j = 0; j < population[i].size(); j++){
                    if (binary){
                        if (RandomNumber(0.0,1.0) > 0.5){
                            population[i][j] = gene_max;
                        }
                        else{
                            population[i][j] = gene_min;
                        }
                    }
                    else{
                        population[i][j] = dis_init(e);
                    }
                }
            }
        }
    } 
    //print chromosomes
    /*
    for (int i = 0; i < population.size(); i++) {
        for (int j = 0; j < population[i].size(); j++) {
            std::cout << population[i][j] << ", ";
        }    
        std::cout << std::endl;
    }*/
    return population;
}

/* Transform chromosome to binary redundancy array */
std::vector<double> DecodeChromosomeFas3(std::vector<double> chromosome, double gene_min, double gene_max)
{   
    std::vector<double> strategy = std::vector<double>(chromosome.size());

    for (int i=0; i<chromosome.size(); i++)  {
        if (chromosome[i] >= (gene_min + gene_max)/2 ) strategy[i] = 1;
        else strategy[i] = 0;
    }

    return strategy;
}

/* Translate a chromosome into weight matrices for neural network controller */
std::vector<Eigen::MatrixXf> DecodeChromosomeANN(std::vector<double> chromosome, int num_output_nodes)
{
    int num_weights = chromosome.size();
    int num_input_nodes = num_output_nodes + 2; // Vi använder bonusvektorn + phi + u som input
    
    // cout << "num_weights = " << num_weights << endl;
    // cout << "num_input_nodes = " << num_input_nodes << endl;
    // cout << "num_output_nodes = " << num_output_nodes << endl;

    int num_hidden_rows = num_input_nodes + 1;
    int num_hidden_nodes = (num_weights - num_output_nodes)/(num_input_nodes + num_output_nodes + 1);
    int num_output_rows = num_hidden_nodes + 1;

    // cout << "num_hidden_rows = " << num_hidden_rows << endl;
    // cout << "num_hidden_nodes = " << num_hidden_nodes << endl;
    // cout << "num_output_rows = " << num_output_rows << endl;

    std::vector<Eigen::MatrixXf> weights(2);
    weights[0].resize(num_hidden_rows, num_hidden_nodes);
    weights[1].resize(num_output_rows, num_output_nodes);

    size_t k = 0;
    for (size_t i=0; i<num_hidden_rows; i++)  {
        for (size_t j=0; j<num_hidden_nodes; j++) {
            weights[0](i,j) = chromosome[k];
            // std::cout << "k=" << k << ", w(" << i << "," << j << ")=" << weights[0](i,j) << endl;
            k += 1;
        }
    }
    for (size_t i=0; i<num_output_rows; i++)  {
        for (size_t j=0; j<num_output_nodes; j++) {
            weights[1](i,j) = chromosome[k];
            // std::cout << "k=" << k << ", w(" << i << "," << j << ")=" << weights[1](i,j) << endl;
            k += 1;
        }
    }
    
//   std::cout << "hidden_weights:\n" << weights[0] << std::endl;
//   std::cout << "output_weights:\n" << weights[1] << std::endl;
  return weights;
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
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, double gene_min, double gene_max, bool binary) {
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
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, int gene_min, int gene_max, bool binary) {
    int chromosome_length = chromosome.size();
    double x=0; 
    double r;
    for (size_t i=0; i<chromosome_length; i++) {
        r = RandomNumber(0.0, 1.0);
        if ( r < mutation_probability) {
            if (RandomNumber(0.0, 1.0) < creep_probability) {

                if (binary){
                if (RandomNumber(0.0,1.0) > 0.5){
                    chromosome[i] = gene_max;
                }
                else{
                    chromosome[i] = gene_min;
                }
                }
                else{
                
                    if (RandomNumber(0.0, 1.0) > 0.5){
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
            }

            else{
                chromosome[i] = RandomNumber(gene_min, gene_max);
            } 
        }
    }

    return chromosome;
}

