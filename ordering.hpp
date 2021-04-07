#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <fstream>
#include <iomanip>
#include <set>
#include <string>
#include "customer.hpp"
#include "order.hpp"
using namespace std;

void validate_parameters(int);
void process_input_file(string, set<Customer *> &);
void process_customer_record(string, set<Customer *> &);
void process_sales_order(string, set<Customer *> &);
bool process_order_details(Order *, set<Customer *> &);
void process_end_of_day(string, set<Customer *> &);
void validate_input_end_of_day(string);
void ship_pending_orders(set<Customer *> &);
void free_allocated_memory(set<Customer *> &);

#endif