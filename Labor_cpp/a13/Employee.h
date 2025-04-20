#ifndef A13_EMPLOYEE_H
   
#define A13_EMPLOYEE_H 

#include <string>
using namespace std;

class Employee
{
    string _first_name;
    string _last_name;
 
public:
    Employee(const string, const string);
    void print() const;
};
#endif // A13_EMPLOYEE_H
