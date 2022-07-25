#include <string>
#include <iostream>
#include <algorithm>

/*
*   A palindromic number reads the same both ways.
*   The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
*   
*   Find the largest palindrome made from the product of two 3-digit numbers.
*   
*   Answer: 906609
*/

bool is_palindrome(uint32_t num) 
{
    auto s = std::to_string(num);
    return std::equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    uint32_t n = 0;

    for (uint32_t i = 999; i > 99; --i)
    {   
        for (uint32_t j = i; j > 99; --j)
        {
            if (i * j <= n) break;
            
            if (is_palindrome(i * j)) 
                n = i * j;
            
        }
    }

    std::cout << n << std::endl;

    return 0;
}