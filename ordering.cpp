#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class NewCustomerRecord
{
    char record_type = 'C';
    int customer_number;
    string customer_name;
};

class SalesOrderRecord
{
    char record_type = 'S';
    int order_date;
    char order_type;
    int order_customer_number;
    int order_quantity;
};

class EndOfDayRecord
{
    char record_type = 'E';
    int end_of_day;
};

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

    read_input_file("orderFile.txt");

    return EXIT_SUCCESS;
}