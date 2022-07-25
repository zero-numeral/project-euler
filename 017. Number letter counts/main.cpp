#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/*
*   If the numbers 1 to 5 are written out in words:
*   one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
*   
*   NOTE: 
*   Do not count spaces or hyphens.
*   For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
*   The use of "and" when writing out numbers is in compliance with British usage.
*   
*   If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
*
*   Answer: 21124
*/

std::string number_to_words(uint64_t num) 
{
    static const std::vector<std::string> m_first { 
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN",
        "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" 
    };
    
   static const std::unordered_map<uint64_t, std::string> m_second {
        {  20, "TWENTY"   }, 
        {  30, "THIRTY"   },  
        {  40, "FORTY"    },  
        {  50, "FIFTY"    },  
        {  60, "SIXTY"    },  
        {  70, "SEVENTY"  }, 
        {  80, "EIGHTY"   }, 
        {  90, "NINETY"   }, 
        { 100, "HUNDRED"  },
        {1000, "THOUSAND" }
        // ... expand for bigger numbers support
    };


    uint64_t p = (uint64_t)log10(num);
    uint64_t p_num = (uint64_t)pow(10, p);

    if (p < 2) // number is lower than 100
    {
        if (num < m_first.size()) 
            return m_first[num];   
        
        uint64_t last_digit = num % 10;
        return (last_digit != 0 ? m_second.find(num - last_digit)->second + "-" + m_first[last_digit]
                                : m_second.find(num)->second);
    }
    
    std::string delim = "";
    uint64_t remainder = num % p_num;

    if (remainder)
    {
        delim = (remainder < 100 ? " AND " : " ");
        delim += number_to_words(remainder);
    }

    return m_first[num / p_num] + " " + m_second.find(p_num)->second + delim;
}

int main()
{
    uint64_t s = 0;

    for (uint64_t i = 1; i <= 1000; ++i)
    {
        auto str = number_to_words(i);
        s += std::count_if(str.begin(), str.end(), [](char ch) { return ch != ' ' && ch != '-'; });
    }

    std::cout << s;

    return 0;
}