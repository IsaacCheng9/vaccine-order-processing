#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
// TODO: Change to include .hpp files instead.
#include "customer.cpp"
#include "sales_order.cpp"
using namespace std;

void validate_parameters(int);
bool process_new_order(SalesOrder *, vector<Customer *> &);
void ship_pending_orders(vector<Customer *> &);
void process_input_file(string, vector<Customer *> &);
void free_allocated_memory(vector<Customer *> &);

#endif