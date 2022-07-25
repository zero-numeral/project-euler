#include <iostream>

/*
*   The sum of the squares of the first ten natural numbers is 1^2 + 2^2 + ... + 10^2 = 385
*   The square of the sum of the first ten natural numbers is  (1 + 2 + ... + 10)^2 = 55^2 = 3025
*   
*   Hence the difference between
*   the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640
*   
*   Find the difference between the sum of the squares of the first 100 natural numbers and the square of the sum.
*   
*   Answer: 25164150
*/

uint64_t sum_of_squares(uint64_t n) 
{
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

uint64_t square_of_sum(uint64_t n)
{
    return (uint64_t)(pow((1 + n) * n / 2, 2));
}

int main()
{
    constexpr uint64_t n = 100;

    std::cout << square_of_sum(n) - sum_of_squares(n) << std::endl;

    return 0;
}