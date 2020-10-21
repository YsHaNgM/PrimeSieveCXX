#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#ifdef _OPENMP
#include <omp.h>
#endif
//#define NDEBUG

// See README.md for instructions and information.

using ptr = std::shared_ptr<int[]>; // gcc-7 is needed, for shared_ptr [] operand c++17 P0414R2
void filter(int &count, int &p, int *val)
{
    *val *= (count % p);
    // if (*val == 1)
    // {
    //     auto mod = (count % p);
    //     switch (mod)
    //     {
    //     case 0:
    //         *val = 0;
    //         break;
    //     default:
    //         break;
    //     }
    // }
};
int main(int argc, char *argv[])
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    auto n = 100;
    ptr numbers(new int[n + 1]);
    std::fill(numbers.get(), numbers.get() + n, 1);
    for (auto p = 2; p <= std::sqrt(n); p++)
    {
        if (numbers[p] != 0)
        {
            for (int count = p * 2; count <= n; count++)
            {
                filter(count, p, numbers.get() + count);
            }
        }
    }
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end - t_start).count()
              << " ms\n";
    for (auto i = 2; i <= n; i++)
    {
        if (numbers[i] != 0)
        {
            std::cout << i << " ";
        }
    }
    return 0;
}
