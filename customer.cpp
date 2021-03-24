#include "customer.hpp"

Customer::Customer(int customer_number_input,
                                     string customer_name_input)
{
    cout << "OP: customer " << setfill('0') << setw(4) <<
    customer_number_input << " added" << endl;;
}