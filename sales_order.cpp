#include "sales_order.hpp"

/* Checks that the input line is valid for a sales order. */
void validate_input_line(string input_line)
{
    bool valid = true;

    /* Sales order input line has a fixed length of 17 characters. */
    if (input_line.length() != 17)
    {
        cerr << "This line in the input file does not have the correct format!"
             << endl;
        valid = false;
    }

    /* Order date should be a number; checks that columns 2-9 only contain
       digits. */
    for (int i = 1; i <= 8; i++)
    {
        if (isdigit(input_line[i]) == 0)
        {
            cerr << "The order date should only contain digits!" << endl;
            valid = false;
        }
    }

    /* Order type should be either 'N' or 'X'. */
    if (input_line[9] != 'N' && input_line[9] != 'X')
    {
        cerr << "The order type should be either 'N' or 'X'!" << endl;
        valid = false;
    }

    /* Order customer number should be a number; checks that columns 11-14 only
       contain digits. */
    for (int i = 10; i <= 13; i++)
    {
        if (isdigit(input_line[i]) == 0)
        {
            cerr << "The order customer number should only contain digits!"
                 << endl;
            valid = false;
        }
    }

    /* Order quantity should be a number; checks that columns 15-17 only
       contain digits. */
    for (int i = 14; i <= 16; i++)
    {
        if (isdigit(input_line[i]) == 0)
        {
            cerr << "The order customer number should only contain digits!"
                 << endl;
            valid = false;
        }
    }

    /* Exits the program if the input file contains an invalid sales order. */
    if (valid == false)
    {
        exit(EXIT_FAILURE);
    }
}

SalesOrder::SalesOrder(string input_line)
{
    validate_input_line(input_line);

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
