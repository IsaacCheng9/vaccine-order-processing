#ifndef __ORDER_HPP
#define __ORDER_HPP

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void ValidateInputOrder(string);
bool IsValidDate(string);

class Order
{
    // In the format YYYYMMDD.
    int order_date;
    // 'N' for a normal order, 'X' for an express order.
    char order_type;
    // Customer number of the customer raising the order.
    int order_customer_number;
    // A three-digit, zero-padded integer.
    int order_quantity;

public:
    Order(string);
    int get_order_date();
    char get_order_type();
    int get_order_customer_number();
    int get_order_quantity();
};

#endif