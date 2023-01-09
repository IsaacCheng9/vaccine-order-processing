# Vaccine Order Processing System

A command-line tool to process customer orders of COVID-19 vaccines for a
shipping company, developed with C++11.

## Building with CMake

To build the program using CMake, run the following commands in the root
directory:

1. Configure the build: `cmake -B build`
2. Run the build: `cmake --build build`

## Usage

Once you have compiled the program, you can run it on an input file with the following command:

`./build/vaccine_order_processing <input_file>`, where `<input_file>` is the
path to the input file.

### Example

We have included an example input file in: [/resources/order_file.txt](resources/order_file.txt)

To run the program on the example file, run the following command in the root directory:

`./build/vaccine_order_processing resources/order_file.txt`

## Input File Format

You can also create your own input file. The program accepts input files with
the following format:

### New Customer Record

| Column Number | Description                                             |
| ------------- | ------------------------------------------------------- |
| 1             | Always 'C'                                              |
| 2-5           | The customer number - a four-digit, zero-padded integer |
| 6-45          | The customer's name                                     |

### Sales Order Record

| Column Number | Description                                                          |
| ------------- | -------------------------------------------------------------------- |
| 1             | Always 'S'                                                           |
| 2-9           | The order date, in the format 'YYYYMMDD'                             |
| 10            | The order type - 'N' for a normal order, or 'X' for an express order |
| 11-14         | The customer number of the customer creating the order               |
| 15-17         | The order quantity - a three-digit, zero-padded integer              |

### End-Of-Day Record

| Column Number | Description                                               |
| ------------- | --------------------------------------------------------- |
| 1             | Always 'E'                                                |
| 2-9           | The date for the end of the day, in the format 'YYYYMMDD' |
