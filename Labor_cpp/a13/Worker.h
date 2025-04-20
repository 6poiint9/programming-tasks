#ifndef A13_WORKER_H
#define A13_WORKER_H

#include "Employee.h"
#include <string>

using namespace std;

class Worker : public Employee
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string, const string, double = 0.0, double = 0.0);
    double get_income() const;
    void print() const;
};
#endif // A13_WORKER_H


