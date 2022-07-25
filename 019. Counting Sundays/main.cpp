#include <chrono>
#include <iostream>

/*
*   You are given the following information, but you may prefer to do some research for yourself.
*   
*   1 Jan 1900 was a Monday.
*   Thirty days has September,
*   April, June and November.
*   All the rest have thirty-one,
*   Saving February alone,
*   Which has twenty-eight, rain or shine.
*   And on leap years, twenty-nine.
*   A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
* 
*   How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)
* 
*   Answer: 171
*/

int main()
{
    using namespace std;
    using namespace chrono;

    uint64_t s = 0;

    for (auto start = 1901y/1/1; start <= 2000y/12/31; start += months(1))
        s += (start._Calculate_weekday() == 0);

    cout << s;

    return 0;
}