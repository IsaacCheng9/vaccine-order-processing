#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include "sales_order.hpp"
using namespace std;

class Customer
{
    /* A four digit, zero-padded integer. */
    int customer_number;
    string customer_name;
    int customer_order_quantity = 0;
    int date;
    /* Keeps track of the latest invoice number. */
    static int invoice_number;

public:
    Customer(string);
    void ship_order();
    void add_quantity(SalesOrder *);
    int get_customer_number();
    int get_customer_order_quantity();
    void set_date(int);
};

#endif