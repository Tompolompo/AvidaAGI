#include <omp.h>
#include <algorithm>
#include <vector>
#include <iostream>



int main()  {

    int num_worlds = 5;
    std::vector<double> test_fitness(num_worlds, 0);

    int n_threads = omp_get_max_threads();
    if (n_threads > num_worlds) n_threads = num_worlds;
    std::cout << "Running with " << n_threads << " threads" << std::endl;
    #pragma omp parallel num_threads(n_threads)
    {
    #pragma omp for
    for (int i=0; i<num_worlds; i++) {

        test_fitness[i] = i+1;
        std::cout << "Thread number: " << omp_get_thread_num() << std::endl;
    }
    }
    int imax = std::max_element(test_fitness.begin(),test_fitness.end()) - test_fitness.begin();

    std::cout << "imax = " << imax << std::endl;
    std::cout << "current_fitness = ";
    for (int i=0; i<num_worlds; i++) {
        std::cout << test_fitness[i] << " ";
    }
    std::cout << std::endl;

}