#include <iostream>

/*
*   The prime factors of 13195 are 5, 7, 13 and 29.
*
*   What is the largest prime factor of the number 600851475143 ?
* 
*   Answer: 6857
*/

void get_largest_pfactor(uint64_t num)
{
    uint64_t factor;

    for (factor = 1; num > 1;) 
    {
        ++factor;
        while (num % factor == 0)
            num /= factor;
    }

    std::cout << factor << std::endl;
}

int main()
{
    constexpr uint64_t num = 600'851'475'143;

    get_largest_pfactor(num);

    return 0;
}