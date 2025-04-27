module; 

import Employee;

#include <iostream>
#include <string>

export module Worker;

export class Worker : public Employee 
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const std::string& f_n, const std::string& l_n, double h_e = 0.0, double h = 0.0)
        : Employee(f_n, l_n), _hourly_earnings(h_e), _hours(h) {}

    double get_income() const {
        return _hourly_earnings;
    }

    void print() const {
        std::cout << "Worker: ";
        Employee::print();
    }
};


