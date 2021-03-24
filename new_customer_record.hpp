#include <iostream>
#include <string>
using namespace std;

class NewCustomerRecord
{
    char record_type = 'C';
    /* A four digit, zero-padded integer. */
    int customer_number;
    string customer_name;

public:
    NewCustomerRecord(int customer_number_input, string customer_name_input);
};