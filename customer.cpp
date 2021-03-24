#include "customer.hpp"

int Customer::invoice_number{1000};

Customer::Customer(string input_line)
{
    this->customer_number = atoi(input_line.substr(1, 4).c_str());
    this->customer_name = input_line.substr(5, 39);
    this->customer_order_quantity = 0;
    this->date = 0;
}

void Customer::ship_order()
{
    cout << "OP: customer " << setfill('0') << setw(4) << customer_number
         << ": shipped quantity " << customer_order_quantity << endl;
    cout << "SC: customer " << customer_number << ": invoice "
         << invoice_number++ << ": date " << date << ": quantity: "
         << customer_order_quantity << endl;
    this->customer_order_quantity = 0;
}

int Customer::get_customer_number()
{
    return this->customer_number;
}

int Customer::get_customer_order_quantity()
{
    return this->customer_order_quantity;
}

void Customer::set_date(int date)
{
    this->date = date;
}
