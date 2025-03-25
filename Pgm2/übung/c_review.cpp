// C++ program to demonstrate the use of virtual function

#include <iostream>
#include <vector>
using namespace std;

class Employee {
    private:
        string first_name;
        string last_name;
    public:
        Employee(string fname, string lname): first_name(fname), last_name(lname) {
        }
        string get_full_name() {
            return first_name + " " + last_name;
        }
        // virtual function to allow overriding
        virtual void print_wage() {
            cout << "The employee's wage structure is not declared yet" << endl;
        }
        // virtual destructor
        virtual ~Employee() {
        }
};

class HourlyEmployee: public Employee {
    private:
        double hourly_wage;
    public:
        HourlyEmployee(string fname, string lname, double wage_per_hour): Employee(fname, lname), hourly_wage(wage_per_hour) {
            
        }
        // overrides the function and provides proper implementation
        // according to the wage structure of HourlyEmployee
        void print_wage() override {
            cout << "The hourly wage of " << get_full_name() << " is " << hourly_wage << endl;
        }
};

class RegularEmployee: public Employee {
    private:
        double monthly_wage;
    public:
        RegularEmployee(string fname, string lname, double wage_per_month): Employee(fname, lname), monthly_wage(wage_per_month) {
            
        }
        // overrides the function and provides proper implementation
        // according to the wage structure of RegularEmployee
        void print_wage() override {
            cout << "The monthly wage of " << get_full_name() << " is " << monthly_wage << endl;
        }
};

int main() {
    // declare a vector to store Employee* pointers pointing to dervied class objects
    vector<Employee*> employees {new HourlyEmployee("John", "Doe", 13.5), new RegularEmployee("Jane", "Smith", 3000.7)};
    for(Employee* employee: employees) {
        employee->print_wage();
    }
    return 0;
}
