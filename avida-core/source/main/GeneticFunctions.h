#ifndef GeneticFunctions_h
#define GeneticFunctions_h

#include <vector>

double RandomNumber(char dist, int min, int max);

char **ParseArgs(int argc, char **argv, int *universe_settings, int &argc_avida);

std::vector<std::vector<double> > InitialisePopulation(int num_worlds, int chromosome_length, int gene_min, int gene_max);

double EvaluateController(double *chromosome, int length);

size_t TournamentSelect(std::vector<double> fitness, double tournament_probability);

std::vector<double> Mutate(std::vector<double> chromosome, double mutation_probability);

std::vector<std::vector<double> > Cross(std::vector<double> chromosome1, std::vector<double> chromosome2);

#endif