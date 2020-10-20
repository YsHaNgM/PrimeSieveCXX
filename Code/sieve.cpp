#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#ifdef _OPENMP
#include <omp.h>
#endif
//#define NDEBUG

// See README.md for instructions and information.

using ptr = std::shared_ptr<int[]>; // gcc-7 is needed, for shared_ptr [] operand c++17 P0414R2

int main(int argc, char *argv[])
{
    auto n = 1000;
    ptr numbers(new int[n]);
    std::fill(numbers.get(), numbers.get() + n, 1);
    auto print = [](const int &n) { std::cout << " " << n; };
    std::for_each(numbers.get(), numbers.get() + n, print);
    return 0;
}
