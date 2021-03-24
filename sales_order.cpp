#include "sales_order.hpp"

SalesOrder::SalesOrder(int order_date_input, char order_type_input,
                                   int order_customer_number_input,
                                   int order_quantity_input)
{
    /* Sets order type name according to whether 'N' or 'E' was provided. */
    string order_type_name;
    if (order_type_input == 'N')
    {
        order_type_name = "normal";
    }
    else if (order_type_input == 'X')
    {
        order_type_name = "EXPRESS";
    }

    cout << "OP: customer " << setfill('0') << setw(4) <<
    order_customer_number_input << ": " << order_type_name <<
    " order: quantity " << setfill('0') << setw(3) << order_quantity_input <<
    endl;
}