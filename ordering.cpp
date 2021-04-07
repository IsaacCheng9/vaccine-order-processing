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

// Reads the input file, and processes the instruction on each line. */
void process_input_file(string file_name, set<Customer *> &customer_record)
{
    string line;
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
    while (getline(file, line))
    {
        if (line[0] == 'C')
        {
            process_customer_record(line, customer_record);
        }
        else if (line[0] == 'S')
        {
            process_sales_order(line, customer_record);
        }
        else if (line[0] == 'E')
        {
            process_end_of_day(line, customer_record);
        }
        // Each input line must start with either 'C', 'S', or 'E'.
        else
        {
            cerr << "This is not a valid input line! Each input line must "
                    "start with either 'C', 'S', or 'E'!"
                 << endl;
            exit(EXIT_FAILURE);
        }
    }
    file.close();
}

// Creates a new customer and adds it to the record. */
void process_customer_record(string line, set<Customer *> &customer_record)
{
    Customer *new_customer = new Customer(line);
    customer_record.insert(new_customer);
    cout << "OP: customer " << setfill('0') << setw(4)
         << new_customer->get_customer_number() << " added" << endl;
}

// Creates a new sales order and processes the information. */
void process_sales_order(string line, set<Customer *> &customer_record)
{
    Order *new_sales_order = new Order(line);
    // Throws an exception if the customer number cannot be matched.
    if (!process_order_details(new_sales_order, customer_record))
    {
        cerr << "The customer number in the order does not match a "
                "customer!"
             << endl;
        exit(EXIT_FAILURE);
    }

    // Free allocated memory for sales order, as it has been processed.
    delete new_sales_order;
}

/* Records the date and quantity of a new order, and processes it if the
   customer number matches a customer on record. */
bool process_order_details(Order *new_sales_order,
                           set<Customer *> &customer_record)
{
    // Whether the customer order must be shipped immediately or not.
    bool is_express = false;

    // Checks all customers on record for a matching customer number.
    for (Customer *customer : customer_record)
    {
        if (customer->get_customer_number() ==
            new_sales_order->get_order_customer_number())
        {
            /* Sets the date of the order, and adds the quantity to the pending
               sales order of the customer. */
            customer->set_date(new_sales_order->get_order_date());
            customer->add_quantity(new_sales_order);

            /* Finds out whether the order was a normal or express order
               according to the mark on the input. */
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

    /* Returns false when the customer number from the order doesn't match any
       customer number from the customer records. */
    return false;
}

// Ships pending customer orders from that day, as the day has ended. */
void process_end_of_day(string line, set<Customer *> &customer_record)
{
    validate_input_end_of_day(line);
    string end_of_day = line.substr(1, 8);
    cout << "OP: end of day " << end_of_day << endl;
    ship_pending_orders(customer_record);
}

// Checks that the input line is valid for the end of the day. */
void validate_input_end_of_day(string line)
{
    bool valid = true;

    // End of day input line has a fixed length of 9 characters.
    if (line.length() > 9)
    {
        cerr << "An input line for an end of day should only contain 9 "
                "characters!"
             << endl;
        valid = false;
    }
    /* End of date should be a number; checks that columns 1-8 only contain
       digits. */
    for (int i = 1; i <= 8; i++)
    {
        if (isdigit(line[i]) == 0)
        {
            cerr << "End of date should only contain digits!" << endl;
            valid = false;
        }
    }

    // Exits the program if the input file contains an invalid end of day.
    if (valid == false)
    {
        exit(EXIT_FAILURE);
    }
}

// Processes customers who have made a normal order at the end of the day. */
void ship_pending_orders(set<Customer *> &customer_record)
{
    // Iterates over customer records to check for unshipped customer orders.
    for (Customer *customer : customer_record)
    {
        if (customer->get_customer_order_quantity() > 0)
        {
            customer->ship_order();
        }
    }
}

// Frees remaining memory allocated for each customer in the record. */
void free_allocated_memory(set<Customer *> &customer_record)
{
    for (Customer *customer : customer_record)
    {
        delete customer;
    }
}

int main(int argc, char **argv)
{
    validate_parameters(argc);
    set<Customer *> customer_record;
    process_input_file(argv[1], customer_record);
    free_allocated_memory(customer_record);
    return EXIT_SUCCESS;
}
