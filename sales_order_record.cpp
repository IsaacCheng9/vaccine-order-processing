#include "sales_order_record.hpp"

SalesOrderRecord::SalesOrderRecord(int order_date_input, char order_type_input,
                                   int order_customer_number_input,
                                   int order_quantity_input)
{
    /* Sets order type name according to whether 'N' or 'E' was provided. */
    string order_type_name;
    if (order_type_input == 'N')
    {
        order_type_name = "normal";
    }
    else if (order_type_input == 'E')
    {
        order_type_name = "EXPRESS";
    }

    cout << "OP: customer " << order_customer_number_input << ": " <<
    order_type_name << " order: quantity " << order_quantity_input;
}