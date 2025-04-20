/* hier */

/* hier */ class Manager /* hier */
{
    double _salary;

public:
    Manager(const string f_n, const string l_n, double s = 0)
    : Employee(f_n, l_n) 
{
    /* HIER */
}
    double get_income() const
{
    /* HIER */
}
void print() const
{
    cout << "Manager: ";
    Employee::print();
}
};


