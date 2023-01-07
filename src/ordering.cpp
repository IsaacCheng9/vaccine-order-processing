#include "ordering.hpp"

// Checks that only one argument has been provided; the input file.
void validate_parameters(int num_args)
{
    if (num_args != 2)
    {
        cerr << "There must only be one argument provided; the name of the "
                "input file!"
             << endl;
        exit(EXIT_FAILURE);
    }
}

// Reads the input file, and processes the instruction on each line.
void process_input_file(string file_name, set<customer *> &customer_record)
{
    string input_line;
    ifstream file;

    // Opens the input file, catching an error if it cannot open this.
    try
    {
        file.open(file_name);
    }
    catch (ifstream::failure e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    // Gets each line in the file.
    while (getline(file, input_line))
    {
        if (input_line[0] == 'C')
        {
            process_customer_record(input_line, customer_record);
        }
        else if (input_line[0] == 'S')
        {
            process_sales_order(input_line, customer_record);
        }
        else if (input_line[0] == 'E')
        {
            process_end_of_day(input_line, customer_record);
        }
        // Each input line must start with either 'C', 'S', or 'E'.
        else
        {
            cerr << "The following input line is not valid - each input line "
                    "must start with either 'C', 'S', or 'E':\n"
                 << input_line
                 << endl;
            exit(EXIT_FAILURE);
        }
    }
    file.close();
}

// Creates a new customer and adds it to the record.
void process_customer_record(string input_line, set<customer *> &customer_record)
{
    customer *new_customer = new customer(input_line);
    customer_record.insert(new_customer);
    cout << "OP: customer " << setfill('0') << setw(4)
         << new_customer->get_customer_number() << " added" << endl;
}

// Creates a new sales order and processes the information.
void process_sales_order(string input_line, set<customer *> &customer_record)
{
    order *new_sales_order = new order(input_line);
    // Throws an exception if the customer number cannot be matched.
    if (!process_order_details(new_sales_order, customer_record))
    {
        cerr << "The customer number in the following order does not match a "
                "customer:\n"
             << input_line << endl;
        exit(EXIT_FAILURE);
    }

    // Free allocated memory for sales order, as it has been processed.
    delete new_sales_order;
}

// Records the date and quantity of a new order, and processes it if the
// customer number matches a customer on record.
bool process_order_details(order *new_sales_order,
                         set<customer *> &customer_record)
{
    // Whether the customer order must be shipped immediately or not.
    bool is_express = false;

    // Checks all customers on record for a matching customer number.
    for (customer *customer : customer_record)
    {
        if (customer->get_customer_number() ==
            new_sales_order->get_order_customer_number())
        {
            // Sets the date of the order, and adds the quantity to the pending
            // sales order of the customer.
            customer->set_date(new_sales_order->get_order_date());
            customer->add_quantity(new_sales_order);

            // Finds out whether the order was a normal or express order
            // according to the mark on the input.
            string order_type_name;
            if (new_sales_order->get_order_type() == 'N')
            {
                order_type_name = "normal";
            }
            else if (new_sales_order->get_order_type() == 'X')
            {
                order_type_name = "EXPRESS";
                is_express = true;
            }

            cout << "OP: customer " << setfill('0') << setw(4)
                 << new_sales_order->get_order_customer_number() << ": "
                 << order_type_name << " order: quantity "
                 << new_sales_order->get_order_quantity() << endl;

            // Express orders must be shipped immediately.
            if (is_express)
            {
                customer->ship_order();
            }

            return true;
        }
    }

    // Returns false when the customer number from the order doesn't match any
    // customer number from the customer records.
    return false;
}

// Ships pending customer orders from that day, as the day has ended.
void process_end_of_day(string input_line, set<customer *> &customer_record)
{
    validate_input_end_of_day(input_line);
    string end_of_day = input_line.substr(1, 8);
    cout << "OP: end of day " << end_of_day << endl;
    ship_pending_orders(customer_record);
}

// Checks that the input line is valid for the end of the day.
void validate_input_end_of_day(string input_line)
{
    bool valid = true;

    // End of day input line has a fixed length of 9 characters.
    if (input_line.length() > 9)
    {
        cerr << "An input line for an end of day should only contain 9 "
                "characters!"
             << endl;
        valid = false;
    }
    // End of date should be a number; checks that columns 1-8 only contain
    // digits.
    for (int i = 1; i <= 8; i++)
    {
        if (isdigit(input_line[i]) == 0)
        {
            cerr << "End of date should only contain digits!" << endl;
            valid = false;
        }
    }
    // Date must be valid.
    if (!is_valid_date(input_line))
    {
        cerr << "This is not a valid date!" << endl;
        valid = false;
    }

    // Exits the program if the input file contains an invalid end of day.
    if (valid == false)
    {
        cerr << "Error in input line containing: " << input_line << endl;
        exit(EXIT_FAILURE);
    }
}

// Processes customers who have made a normal order at the end of the day.
void ship_pending_orders(set<customer *> &customer_record)
{
    // Iterates over customer records to check for unshipped customer orders.
    for (customer *customer : customer_record)
    {
        if (customer->get_customer_order_quantity() > 0)
        {
            customer->ship_order();
        }
    }
}

// Frees remaining memory allocated for each customer in the record.
void free_allocated_customer_memory(set<customer *> &customer_record)
{
    for (customer *customer : customer_record)
    {
        delete customer;
    }
}

int main(int argc, char **argv)
{
    validate_parameters(argc);
    set<customer *> customer_record;
    process_input_file(argv[1], customer_record);
    free_allocated_customer_memory(customer_record);
    return EXIT_SUCCESS;
}
