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
    int customer_order_quantity;
    int date;
    static int invoice_number;

public:
    Customer(string);
    void ship_order();
    int get_customer_number();
    int get_customer_order_quantity();
    void set_date(int);
};

#endif