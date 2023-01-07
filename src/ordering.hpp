#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include "customer.hpp"
#include "order.hpp"
using namespace std;

void validate_parameters(int);
void process_input_file(string, set<customer *> &);
void process_customer_record(string, set<customer *> &);
void process_sales_order(string, set<customer *> &);
bool process_order_details(order *, set<customer *> &);
void process_end_of_day(string, set<customer *> &);
void validate_end_of_day_input(string);
void ship_pending_orders(set<customer *> &);
void free_allocated_customer_memory(set<customer *> &);

#endif