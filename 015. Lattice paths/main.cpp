#include <iostream>

/*
*   https://en.wikipedia.org/wiki/Lattice_path
*   https://en.wikipedia.org/wiki/Combination
* 
*   Starting in the top left corner of a 2x2 grid,
*   and only being able to move to the right and down,
*   there are exactly 6 routes to the bottom right corner.
*   
*   How many such routes are there through a 20x20 grid?
* 
*   Answer: 137846528820
*/

double lattice_paths(uint64_t num)
{
    auto f = [] (uint64_t n) -> double { return std::tgamma(n + 1); };

    uint64_t n = 2 * num;
    uint64_t k = num;


    return (f(n) / (f(n - k) * f(k)));
}

int main()
{
    std::cout << std::fixed << lattice_paths(20);

    return 0;
}