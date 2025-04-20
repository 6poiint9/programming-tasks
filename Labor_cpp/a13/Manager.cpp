#include <iostream>
#include "Manager.h"
using namespace std;



Manager::Manager(const string f_n, const string l_n, double s = 0)
    : Employee(f_n, l_n) 
{
   _salary = s;   
}
double Manager::get_income() const
{
    return _salary; 
}
void Manager::print() const
{
    cout << "Manager: ";
    Employee::print();
}
