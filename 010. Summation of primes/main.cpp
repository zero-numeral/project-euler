#include <vector>
#include <iostream>

/*
*   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*   
*   Find the sum of all the primes below two million.
* 
*   Answer: 142913828922
*/

std::vector<bool> sieve(const uint64_t n) 
{
    std::vector<bool> primes(n, true);
    primes[0] = primes[1] = false;

    for (uint64_t p = 2; p < sqrt(n); ++p)
        if (primes[p])
            for (uint64_t i = p * p; i < n; i += p)
                primes[i] = false;

    return primes;
}

int main()
{
    auto primes = sieve(2'000'000);
    uint64_t sum {};

    for (uint64_t i = 2; i < primes.size() ; ++i)
        if (primes[i])
            sum += i;

    std::cout << sum << std::endl;

    return 0;
}