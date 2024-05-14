#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <vector>

class Fibonacci {
public:
    Fibonacci(int n);
    unsigned long int getOMP(int n);
    unsigned long int get(int n);
    void computeOMP();
    void compute();

private:
    std::vector<unsigned long int> memoryOMP;
    std::vector<unsigned long int> memory;
    unsigned long int fibonacciOMP(int n);
    unsigned long int fibonacci(int n);

};

#endif
