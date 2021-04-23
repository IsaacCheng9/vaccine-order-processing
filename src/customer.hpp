#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include "order.hpp"
using namespace std;

void ValidateInputCustomer(string);

class Customer
{
    // A four digit, zero-padded integer.
    int customer_number;
    string customer_name;
    int customer_order_quantity = 0;
    int date;
    // Keeps track of the next invoice number to issue.
    static int invoice_number;

public:
    Customer(string);
    void ShipOrder();
    void AddQuantity(Order *);
    int get_customer_number();
    int get_customer_order_quantity();
    void set_date(int);
};

#endif