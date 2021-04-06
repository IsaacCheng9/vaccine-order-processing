#include "ordering.hpp"

/* Checks that only one argument has been provided; the input file. */
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

/* Records the date and quantity of a new order, and processes it if the
   customer number matches a customer on record. */
bool process_new_order(SalesOrder *new_sales_order,
                       vector<Customer *> &customer_record)
{
    /* Whether the customer order must be shipped immediately or not. */
    bool is_express = false;

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

            /* Express orders must be shipped immediately. */
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

/* Processes customers who have made a normal order at the end of the day. */
void ship_pending_orders(vector<Customer *> &customer_record)
{
    for (Customer *customer : customer_record)
    {
        if (customer->get_customer_order_quantity() > 0)
        {
            customer->ship_order();
        }
    }
}

/* Reads the input file, and processes the instruction on each line. */
void process_input_file(string file_name, vector<Customer *> &customer_record)
{
    string line;
    ifstream file;

    /* Opens the input file, catching an error if it cannot open this. */
    try
    {
        file.open(file_name);
    }
    catch (ifstream::failure e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    /* Gets each line in the file. */
    while (getline(file, line))
    {
        /* Processes a new customer record. */
        if (line[0] == 'C')
        {
            Customer *new_customer = new Customer(line);
            customer_record.push_back(new_customer);
            cout << "OP: customer " << setfill('0') << setw(4)
                 << new_customer->get_customer_number() << " added" << endl;
        }

        /* Processes a sales order. */
        else if (line[0] == 'S')
        {
            SalesOrder *new_sales_order = new SalesOrder(line);

            /* Throws an exception if the customer number cannot be matched. */
            if (!process_new_order(new_sales_order, customer_record))
            {
                cerr << "The customer number in the order does not match a "
                        "customer!"
                     << endl;
                exit(EXIT_FAILURE);
            }

            /* Free allocated memory for sales order, as it has been
               processed. */
            delete new_sales_order;
        }

        /* Ships pending customer orders from that day, as the day has ended. */
        else if (line[0] == 'E')
        {
            string end_of_day = line.substr(1, 8);
            cout << "OP: end of day " << end_of_day << endl;
            ship_pending_orders(customer_record);
        }
    }
    file.close();
}

/* Frees remaining allocated memory once the program has finished. */
void free_allocated_memory(vector<Customer *> &customer_record)
{
    for (Customer *customer : customer_record)
    {
        delete customer;
    }
}

int main(int argc, char **argv)
{
    validate_parameters(argc);
    vector<Customer *> customer_record;
    process_input_file(argv[1], customer_record);
    free_allocated_memory(customer_record);

    return EXIT_SUCCESS;
}
