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
    /* A four digit, zero-padded integer. */
    int customer_number;
    string customer_name;

public:
    NewCustomerRecord(int customer_number_input, string customer_name_input);
};

NewCustomerRecord::NewCustomerRecord(int customer_number_input,
                                     string customer_name_input)
{
    cout << "OP: customer " << customer_number_input << "added";
}

class SalesOrderRecord
{
    char record_type = 'S';
    /* In the format YYYYMMDD. */
    int order_date;
    /* 'N' for a normal order, 'X' for an express order. */
    char order_type;
    /* Customer number of the customer raising the order. */
    int order_customer_number;
    /* A three-digit, zero-padded integer. */
    int order_quantity;

public:
    SalesOrderRecord(int order_date_input, char order_type_input,
                     int order_customer_number_input, int order_quantity_input);
};

SalesOrderRecord::SalesOrderRecord(int order_date_input, char order_type_input,
                                   int order_customer_number_input,
                                   int order_quantity_input)
{
    /* Sets order type name according to whether 'N' or 'E' was provided. */
    string order_type_name;
    if (order_type_input == 'N')
    {
        order_type_name = "normal";
    }
    else if (order_type_input == 'E')
    {
        order_type_name = "EXPRESS";
    }

    cout << "OP: customer " << order_customer_number_input << ": " <<
    order_type_name << " order: quantity " << order_quantity_input;
}

class EndOfDayRecord
{
    char record_type = 'E';
    /* The date for which this is the end of the day, in the format YYYYMMDD. */
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