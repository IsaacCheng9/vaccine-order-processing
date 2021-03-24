#include <iostream>
#include <string>
using namespace std;

class EndOfDayRecord
{
    char record_type = 'E';
    /* The date for which this is the end of the day, in the format YYYYMMDD. */
    int end_of_day;

public:
    EndOfDayRecord(int end_of_day);
};