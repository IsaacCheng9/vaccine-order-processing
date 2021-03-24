#include "sales_order.hpp"

SalesOrder::SalesOrder(string input_line)
{
    if (input_line.length() != 17)
    {
        cerr << "This line in the input file does not have the correct format!" << endl;
        exit(EXIT_FAILURE);
    }

    this->order_date = atoi(input_line.substr(1, 8).c_str());
    this->order_type = input_line[9];
    this->order_customer_number = atoi(input_line.substr(10, 4).c_str());
    this->order_quantity = atoi(input_line.substr(14, 3).c_str());
}

int SalesOrder::get_order_date()
{
    return this->order_date;
}

char SalesOrder::get_order_type()
{
    return this->order_type;
}

int SalesOrder::get_order_customer_number()
{
    return this->order_customer_number;
}

int SalesOrder::get_order_quantity()
{
    return this->order_quantity;
}
