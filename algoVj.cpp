#include <stdio.h>
#include <iostream>
#include "fibonacci.h"
#include <chrono>
#include <omp.h>
#include <iomanip>

int main() {
    const int N = 60;

    int max_threads = omp_get_max_threads();
    std::cout << "Max threads in this CPU: " << max_threads << std::endl;
    omp_set_num_threads(max_threads);

    Fibonacci fibonacci(N);

    std::cout << "---Fibonacci sequence---" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    fibonacci.compute();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    for (int i = 0; i <= N; i++) {
        std::cout << i << " - " << fibonacci.get(i) << std::endl;
    }

    std::cout << "---Fibonacci sequence OMP---" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    fibonacci.computeOMP();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;

    std::cout << std::endl << "------Summary------" << std::endl;
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "The 1st run - execution time without OpenMP: " << duration.count() << " seconds" << std::endl;
    std::cout << "The 2nd run - execution time with OpenMP: " << duration2.count() << " seconds" << std::endl;

    return 0;
}
