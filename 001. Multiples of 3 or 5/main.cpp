#include <iostream>

/*
*   If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
*   The sum of these multiples is 23.
*   
*   Find the sum of all the multiples of 3 or 5 below 1000.
*   
*   Answer: 233168
*/

void method_1(const uint32_t limit) 
{
    uint32_t sum = 0;

    for (uint32_t three = 0, five = 0; three <= limit || five <= limit;)
    {
        if (three += 3; three <= limit) 
            sum += three;
        

        if (five += 5; five <= limit && five % 15 != 0)
            sum += five;
    }

    std::cout << sum << std::endl;
}

uint32_t sum_till(const uint32_t n) 
{
    return (1 + n) * n / 2;
}

void method_2(const uint32_t limit)
{
    std::cout << 3  * sum_till(limit / 3) +
                 5  * sum_till(limit / 5) - 
                 15 * sum_till(limit / 15) << std::endl;
}

int main()
{
    /* inclusively */
    constexpr uint32_t limit = 999;

    method_1(limit);
    method_2(limit);

    return 0;
}