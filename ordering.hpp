#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <fstream>
#include <iomanip>
#include <set>
#include <string>
#include "customer.cpp"
#include "order.cpp"
using namespace std;

void ValidateParameters(int);
void ProcessInputFile(string, set<Customer *> &);
void ProcessCustomerRecord(string, set<Customer *> &);
void ProcessSalesOrder(string, set<Customer *> &);
bool ProcessOrderDetails(Order *, set<Customer *> &);
void ProcessEndOfDay(string, set<Customer *> &);
void ValidateInputEndOfDay(string);
void ShipPendingOrders(set<Customer *> &);
void FreeAllocatedMemory(set<Customer *> &);

#endif