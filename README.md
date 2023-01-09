# Vaccine Order Processing System

A command-line tool to process customer orders of COVID-19 vaccines for a
shipping company, developed with C++11.

## Compilation

To compile the program using CMake, run the following commands in the root
directory:

1. Configure the build: `cmake -B build`
2. Run the build: `cmake --build build`

## Usage

Once you have compiled the program, you can run it on an input file. We have
included an example in: [/resources/order_file.txt](resources/order_file.txt)

To run the program on the example file, run the following command in the root
directory:
`./build/vaccine_order_processing resources/order_file.txt`
