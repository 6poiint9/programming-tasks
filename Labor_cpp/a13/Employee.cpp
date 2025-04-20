#include <iostream>
#include <string>

#include "Employee.h"
using namespace std;


Employee::Employee(const string f_n, const string l_n)
 : _first_name{f_n}, _last_name{l_n} {} 

void Employee::print() const
{
    cout << _last_name << ", " << _first_name << endl;
}


