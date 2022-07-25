#include <iostream>

/*
*   A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*   
*   a^2 + b^2 = c^2
*   For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*   
*   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
*   Find the product abc.
* 
*   Answer: 31875000
*/

bool is_pythagorean_triplet(const uint64_t a,
                            const uint64_t b,
                            const uint64_t c)
{
    return a * a + b * b == c * c;
}

int main()
{
    for (uint64_t a = 0; a < 400; ++a) 
    {
        for (uint64_t b = a + 1; b < 400; ++b) 
        {
            uint64_t c = 1000 - b - a;

            if (is_pythagorean_triplet(a, b, c))
            {
                std::cout << a * b * c;
                exit(0);
            }
        }
    }

    return 0;
}