#include <vector>
#include <numeric>
#include <iostream>

/*
*   n! means n x (n - 1) x ... x 3 x 2 x 1
*   
*   For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800
*   and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27
*   
*   Find the sum of the digits in the number 100!
*   
*   Answer: 648
*/

void mul(std::vector<uint32_t>& v, uint32_t num)
{
    uint32_t carry = 0;

    for (auto& digit : v) 
    {
        carry = carry + digit * num;

        digit = carry % 10;
        carry /= 10;
    }

    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

int main()
{
    std::vector <uint32_t> v;
    v.reserve(500);

    v.push_back(1);
    for (uint32_t i = 2; i <= 100; ++i)
        mul(v, i);

    std::cout << std::accumulate(v.begin(), v.end(), 0);

    return 0;
}