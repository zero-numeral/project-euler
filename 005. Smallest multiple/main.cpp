#include <ranges>
#include <numeric>
#include <iostream>

/*
*   2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*
*   What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
* 
*   Answer: 232792560
*/

void func(std::ranges::iota_view<int, int> range) 
{
    int v = *(range.begin());

    for (auto it = ++range.begin(); it != range.end(); ++it)
        v = std::lcm(v, *it);
    
    std::cout << v << std::endl;
}

int main()
{
    // 2520 factors: 2^3, 3^2, 5, 7
    // evenly divisible number (till 20) factors: 2^4, 3^2, 5, 7, 11, 13, 17, 19 
    std::cout << std::fixed << pow(2, 4) * pow(3, 2) * 5 * 7 * 11 * 13 * 17 * 19 << std::endl;

    func(std::views::iota(2, 20));
    func(std::views::iota(2, 10));
    
    return 0;
}