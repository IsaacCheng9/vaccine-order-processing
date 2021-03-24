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
        if (line[0] == 'C')
        {
            string temp = line.substr(1, 4);
            int customer_number_input = stoi(temp);
            string customer_name_input;
            Customer c1(customer_number_input, customer_name_input);
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