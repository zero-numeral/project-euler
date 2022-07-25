#include <iostream>

/*
*   The following iterative sequence is defined for the set of positive integers:
*   n -> n/2    (n is even)
*   n -> 3n + 1 (n is odd)
*   
*   Which starting number, under one million, produces the longest chain?
* 
*   Answer: 837799
*/


uint64_t get_chain_length(uint64_t num) 
{
    uint64_t count = 0;

    while (num != 1) 
    {
        num = (num & 1 ? 3 * num + 1 : num >> 1);
        count++;
    }

    return count;
}

int main()
{
    uint64_t max_length = 0;
    uint64_t num = 0;

    for (uint64_t i = 1; i < 1'000'000; ++i) 
    {
        uint64_t length = get_chain_length(i);
        if (length > max_length) 
        {
            max_length = length;
            num = i;
        }
    }

    std::cout << num;

    return 0;
}