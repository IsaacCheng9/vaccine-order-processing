#include "customer.hpp"

// Sets the invoice number to start at 1000.
int Customer::invoice_number = 1000;

// Checks that the input line is valid for a new customer.
void ValidateInputCustomer(string input_line)
{
    bool valid = true;

    // New customer input line has a maximum length of 45 characters.
    if (input_line.length() > 45)
    {
        cerr << "An input line for a customer order should not contain more "
                "45 characters!"
             << endl;
        valid = false;
    }
    // Customer number should be a number; checks that columns 2-5 only contain
    // digits.
    for (int i = 1; i <= 4; i++)
    {
        if (isdigit(input_line[i]) == 0)
        {
            cerr << "Customer number should only contain digits!" << endl;
            valid = false;
        }
    }

    // Exits the program if the input file contains an invalid sales order.
    if (valid == false)
    {
        exit(EXIT_FAILURE);
    }
}

Customer::Customer(string input_line)
{
    ValidateInputCustomer(input_line);
    // Customer number is contained on columns 2-5, and customer name is
    // contained on columns 6-45.
    this->customer_number = atoi(input_line.substr(1, 4).c_str());
    this->customer_name = input_line.substr(5, 40);
}

// Ships the customer's order, and displays an invoice with the invoice number,
// date, and quantity shipped.
void Customer::ShipOrder()
{
    cout << "OP: customer " << setfill('0') << setw(4) << customer_number
         << ": shipped quantity " << customer_order_quantity << endl;
    cout << "SC: customer " << setfill('0') << setw(4) << customer_number
         << ": invoice " << invoice_number++ << ": date " << date
         << ": quantity: " << customer_order_quantity << endl;

    // Resets the customer quantity, as current quantity has been shipped.
    this->customer_order_quantity = 0;
}

// Adds the quantity of a new sales order to the customer's total pending
// order quantity.
void Customer::AddQuantity(Order *new_sales_order)
{
    this->customer_order_quantity += new_sales_order->get_order_quantity();
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
