#include "fibonacci.h"
#include <omp.h>
#include <iostream>

Fibonacci::Fibonacci(int n) {
    memory.resize(n + 1, 0);
    memoryOMP.resize(n + 1, 0);
}

unsigned long int Fibonacci::fibonacci(int n) {
    if (n <= 1) return n;
    if (memory[n] != 0) return memory[n];
    unsigned long int result = fibonacci(n - 1) + fibonacci(n - 2);
    memory[n] = result;
    return result;
}

unsigned long int Fibonacci::get(int n) {
    if (memory[n] == 0) {
        fibonacci(n);
    }
    return memory[n];
}

void Fibonacci::compute() {
    for (int i = 0; i < memory.size(); i++) {
        memory[i] = get(i);
    }
}

unsigned long int Fibonacci::fibonacciOMP(int n) {
    if (n <= 1) return n;
    if (memoryOMP[n] != 0) return memoryOMP[n];
    unsigned long int result = fibonacciOMP(n - 1) + fibonacciOMP(n - 2);
    memoryOMP[n] = result;
    return result;
}

unsigned long int Fibonacci::getOMP(int n) {
    if (memoryOMP[n] == 0) {
        fibonacciOMP(n);
    }
    return memoryOMP[n];
}

void Fibonacci::computeOMP() {
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < memoryOMP.size(); i++) {
        memoryOMP[i] = getOMP(i);
#pragma omp critical
        {
            std::cout << i << " - " << memoryOMP[i] << " - Calculated by thread: " << omp_get_thread_num() << std::endl;
        }
    }
}

