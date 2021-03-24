#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Customer
{
    /* A four digit, zero-padded integer. */
    int customer_number;
    string customer_name;

public:
    Customer(int customer_number_input, string customer_name_input);
};

#endif