#include <vector>
#include <iostream>
#include "mpi.h"

using namespace std;

void print(std::vector<int> const &input)
{
    for (auto const& i: input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void print(std::vector<double> const &input)
{
    for (auto const& i: input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)  {

    // Initiate MPI and forward arguments
    MPI_Init(&argc, &argv);
    int num_procs, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int root = num_procs-1;

    int num_worlds = 4;
    int chromosome_length = 6;
    int num_meta_generations = 3;

    std::vector<std::vector<double> > controllers = std::vector<std::vector<double> >(num_worlds, std::vector<double>(chromosome_length));
    for (int i=0; i<num_worlds; i++) {
        for (int j=0; j<chromosome_length; j++)
            controllers[i][j] = i*j+1;      
    }

    if (rank == root)   {
        cout << "controllers:" << endl;
        for (std::vector<double> row : controllers)    {
            print(row);
        }
    }


    for (size_t imeta = 0; imeta < num_meta_generations; imeta++)   {

        std::vector<double> current_fitness(num_worlds);

        for (int i=0; i<num_worlds; i++) {
            // cout << "rank " << rank <<": " << "controllers[" << i <<"]: ";
            for (int j=0; j<chromosome_length; j++) {
                // cout << controllers[i][j] << " ";
                MPI_Bcast(&controllers[i][j], 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
            }
            // cout << endl;
        }

        std::vector<double> chromosome(chromosome_length);
        MPI_Scatter(&controllers[0], num_worlds*chromosome_length, MPI_DOUBLE , &chromosome[0], chromosome_length , MPI_DOUBLE, root, MPI_Comm communicator);

        int limit = num_worlds/num_procs;
        int rank_num = rank+1;
        int end = rank_num*limit-1, start = rank_num*limit-limit;

        cout << "rank: " << rank << endl;
        cout << "start: " << start << endl;
        cout << "end: " << end << endl;
        int i=0;
        for (int iworld=start; iworld<=end; iworld++)   {
            i++;
            for (int j = 0; j < chromosome_length; j++) {
                current_fitness[iworld] = controllers[iworld][j];
                cout << current_fitness[iworld] << " ";
            }
            cout << endl;
        }
        
        MPI_Send(&current_fitness[0], num_worlds, MPI_DOUBLE, root, 0, MPI_COMM_WORLD);

        if (rank == root)   {

            std::vector<std::vector<double> > fitnesses = std::vector<std::vector<double> >(num_procs, std::vector<double>(num_worlds, 0));
            std::vector<double> buffer(num_worlds, 0);

            for (int i=0; i<num_procs; i++) {
                MPI_Recv(&buffer[0], num_worlds, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                
                for (int j = 0; j < num_worlds; j++)
                    fitnesses[i][j] = buffer[j];
            }
            // Sum up fitness
            for (size_t i=0; i<num_worlds; i++) {
                double colsum = 0;
                for (size_t j=0; j<num_procs; j++) {
                    colsum += fitnesses[j][i];
                }
                current_fitness[i] = colsum;
            }
            
            cout << "fitness[" << imeta << "]:" << endl;
            print(current_fitness);

            for (int i=0; i<num_worlds; i++) {
                // cout << "rank " << rank <<": " << "controllers[" << i <<"]: ";
                for (int j=0; j<chromosome_length; j++) {
                    // cout << controllers[i][j] << " ";
                    controllers[i][j] += 1;
                }
                // cout << endl;
            }   

        }

        // MPI_Barrier(MPI_COMM_WORLD);
    }


MPI_Finalize();

}