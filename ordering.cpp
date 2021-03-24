#include <fstream>
#include <iomanip>
#include <vector>
#include "customer.cpp"
#include "sales_order.cpp"

void validate_parameters(int num_args)
{
    /* Checks that an input file has been provided as an argument. */
    if (num_args != 2)
    {
        cerr << "No input file has been provided!" << endl;
        exit(EXIT_FAILURE);
    }
}

bool process_new_order(SalesOrder *new_sales_order, vector<Customer *> &customer_record)
{
    for (Customer *customer : customer_record)
    {
        if (customer->get_customer_number() == new_sales_order->get_order_customer_number())
        {
            customer->set_date(new_sales_order->get_order_date());

            /* Sets order type name according to whether 'N' or 'E' was
            provided. */
            string order_type_name;
            if (new_sales_order->get_order_type() == 'N')
            {
                order_type_name = "normal";
            }
            else if (new_sales_order->get_order_type() == 'X')
            {
                order_type_name = "EXPRESS";
            }

            cout << "OP: customer " << setfill('0') << setw(4) << new_sales_order->get_order_customer_number() << ": " << order_type_name << " order: quantity " << setfill('0') << setw(3) << new_sales_order->get_order_quantity() << endl;

            return true;
        }
    }
    return false;
}

void process_input_file(string file_name, vector<Customer *> &customer_record)
{
    string line;
    ifstream file;
    /* Throws an exception when EOF is reached. */
    file.exceptions(ifstream::eofbit);

    /* Opens the input file. */
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

            cout << "OP: customer " << setfill('0') << setw(4) << new_customer->get_customer_number() << " added" << endl;
        }

        /* Processes a sales order. */
        else if (line[0] == 'S')
        {
            SalesOrder *new_sales_order = new SalesOrder(line);

            if (!process_new_order(new_sales_order, customer_record))
            {
                cerr << "There was an order in an invalid format!" << endl;
                exit(EXIT_FAILURE);
            }
        }

        /* Processes an end-of-day record. */
        else if (line[0] == 'E')
        {
            string end_of_day = line.substr(1, 8);
            cout << "OP: end of day " << end_of_day << endl;
        }
    }
}

int main(int argc, char **argv)
{
    validate_parameters(argc);
    vector<Customer *> customer_record;
    process_input_file(argv[1], customer_record);

    return EXIT_SUCCESS;
}
