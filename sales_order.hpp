#ifndef SALES_ORDER_HPP
#define SALES_ORDER_HPP

#include <iostream>
#include <string>
using namespace std;

class SalesOrder
{
    char record_type = 'S';
    /* In the format YYYYMMDD. */
    int order_date;
    /* 'N' for a normal order, 'X' for an express order. */
    char order_type;
    /* Customer number of the customer raising the order. */
    int order_customer_number;
    /* A three-digit, zero-padded integer. */
    int order_quantity;

public:
    SalesOrder(int order_date_input, char order_type_input,
                     int order_customer_number_input, int order_quantity_input);
};

#endif