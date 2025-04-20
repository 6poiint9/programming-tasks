#include <iostream>
#include "Worker.h"

using namespace std;

Worker::Worker(const string f_n, const string l_n,
                   double h_e, double h)
    : Employee(f_n, l_n)
{
   _hourly_earnings = h_e;
   _hours = h; 
}
double Worker::get_income() const
{
    return _hourly_earnings; 
}

void Worker::print() const
{
    cout << "Worker: ";
    Employee::print();
}
