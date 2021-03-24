#include <fstream>
#include <iomanip>
#include "customer.cpp"
#include "sales_order.cpp"
#include "end_of_day.cpp"

void read_input_file(string filename)
{
    ifstream input_file(filename);
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