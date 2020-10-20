#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#ifdef _OPENMP
#include <omp.h>
#endif
//#define NDEBUG

// See README.md for instructions and information.

using ptr = std::shared_ptr<double[]>; // gcc-7 is needed, for shared_ptr [] operand c++17 P0414R2

int main(int argc, char *argv[])
{
    auto n = 1000;
    auto numbers = std::make_shared<int[]>(n);
    std::fill(numbers.get(), numbers.get() + n, 1);
    return 0;
}
