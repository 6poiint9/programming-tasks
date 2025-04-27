module; 

import Employee;  

#include <iostream>
#include <string>

export module Manager; 

export class Manager : public Employee 
{
    double _salary;

public:
    Manager(const std::string f_n, const std::string l_n, double s = 0)
    : Employee(f_n, l_n) 
{
    _salary = s; 
}
    double get_income() const
{
    return _salary; 
}
void print() const
{
    std::cout << "Manager: ";
    Employee::print();
}
};


