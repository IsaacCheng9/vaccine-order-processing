#include "customer.hpp"

Customer::Customer(string input_line)
{
    if (input_line.length() != 45)
    {
        cerr << "This line in the input file does not have the correct format!" << endl;
        exit(EXIT_FAILURE);
    }

    this->customer_number = atoi(input_line.substr(1, 4).c_str());
    this->customer_name = input_line.substr(5, 39);
    this->customer_order_quantity = 0;
    this->date = 0;
}