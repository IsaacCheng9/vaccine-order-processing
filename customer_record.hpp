#include <iostream>
#include <string>
using namespace std;

class CustomerRecord
{
    char record_type = 'C';
    /* A four digit, zero-padded integer. */
    int customer_number;
    string customer_name;

public:
    CustomerRecord(int customer_number_input, string customer_name_input);
};