#include <fstream>
#include <iomanip>
#include "customer.cpp"
#include "sales_order.cpp"
#include "end_of_day.cpp"

void read_input_file(string file_name)
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
            string temp_customer_number = line.substr(1, 4);
            int customer_number_input = stoi(temp_customer_number);
            string customer_name_input;

            Customer c1(customer_number_input, customer_name_input);
        }
        /* Processes a sales order. */
        else if (line[0] == 'S')
        {
            string temp_order_date = line.substr(1, 8);
            string temp_order_customer_number = line.substr(10, 4);
            string temp_order_quantity = line.substr(14, 3);
            int order_date_input = stoi(temp_order_date);
            char order_type_input = line[9];
            int order_customer_number_input = stoi(temp_order_customer_number);
            int order_quantity_input = stoi(temp_order_quantity);

            SalesOrder s1(order_date_input, order_type_input,
                          order_customer_number_input, order_quantity_input);
        }
        /* Processes an end-of-day record. */
        else if (line[0] == 'E')
        {
            string temp_end_of_day = line.substr(1, 8);
            int end_of_day = stoi(temp_end_of_day);

            EndOfDay e1(end_of_day);
        }
    }
}

int main(int argc, char **argv)
{
    /* Checks that an input file has been provided as an argument. */
    if (argc != 2)
    {
        cerr << "No input file has been provided!" << endl;
        exit(EXIT_FAILURE);
    }

    read_input_file(argv[1]);

    return EXIT_SUCCESS;
}