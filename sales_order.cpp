#include "sales_order.hpp"

SalesOrder::SalesOrder(string input_line)
{
    /* Sales order input line has a fixed format of 17 characters. */
    if (input_line.length() != 17)
    {
        cerr << "This line in the input file does not have the correct format!"
             << endl;
        exit(EXIT_FAILURE);
    }

    /* Order date is contained on columns 2-9, order type is contained on
       column 10, order customer number is contained on columns 11-14, and
       order quantity is contained on columns 15-17. */
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
