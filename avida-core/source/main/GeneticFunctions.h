#ifndef GeneticFunctions_h
#define GeneticFunctions_h

#include <vector>

double RandomNumber(double min, double max);
int RandomNumber(int min, int max);



std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, double gene_min, double gene_max);
std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, int gene_min, int gene_max);

double EvaluateController(double *chromosome, int length);

size_t TournamentSelect(std::vector<double> fitness, double tournament_probability);

std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, double gene_min, double gene_max);
std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability, double creep_rate, double creep_probability, int gene_min, int gene_max);

std::vector<std::vector<double> > Cross(std::vector<double> chromosome1, std::vector<double> chromosome2);

#endif