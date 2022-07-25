#include <iostream>

/*
*   By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*   
*   What is the 10 001st prime number?
* 
*   Answer: 104743
*/

bool is_prime(uint64_t n)
{
    if (n == 2 || n == 3) return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;

    for (uint64_t i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true; 
}

int main()
{
    constexpr uint64_t n = 10001;
    
    uint64_t count = 1;
    uint64_t nth_prime = 2;

    for (uint64_t i = 3; count < n; i += 2) 
    {
        if (is_prime(i))
        {
            nth_prime = i;
            count++;
        }
    }

    std::cout << nth_prime << std::endl;

    return 0;
}