#include <fstream>
#include <iomanip>
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

void process_input_file(string file_name)
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

            cout << "OP: customer " << setfill('0') << setw(4) <<
            customer_number_input << " added" << endl;;
        }
        /* Processes a sales order. */
        else if (line[0] == 'S')
        {
            string order_date_input = line.substr(1, 8);
            char order_type_input = line[9];
            string order_customer_number_input = line.substr(10, 4);
            string order_quantity_input = line.substr(14, 3);

            /* Sets order type name according to whether 'N' or 'E' was provided. */
            string order_type_name;
            if (order_type_input == 'N')
            {
                order_type_name = "normal";
            }
            else if (order_type_input == 'X')
            {
                order_type_name = "EXPRESS";
            }

            cout << "OP: customer " << setfill('0') << setw(4) <<
            order_customer_number_input << ": " << order_type_name <<
            " order: quantity " << setfill('0') << setw(3) <<
            order_quantity_input << endl;
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
    process_input_file(argv[1]);

    return EXIT_SUCCESS;
}
