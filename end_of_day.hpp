#ifndef END_OF_DAY_HPP
#define END_OF_DAY_HPP

#include <iostream>
#include <string>
using namespace std;

class EndOfDay
{
    char record_type = 'E';
    /* The date for which this is the end of the day, in the format YYYYMMDD. */
    int end_of_day;

public:
    EndOfDay(int end_of_day);
};

#endif