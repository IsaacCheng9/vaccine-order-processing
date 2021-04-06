#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <fstream>
#include <iomanip>
#include <set>
#include <string>
// TODO: Change to include .hpp files instead.
#include "customer.cpp"
#include "sales_order.cpp"
using namespace std;

void validate_parameters(int);
bool process_new_order(SalesOrder *, set<Customer *> &);
void ship_pending_orders(set<Customer *> &);
void process_input_file(string, set<Customer *> &);
void free_allocated_memory(set<Customer *> &);

#endif