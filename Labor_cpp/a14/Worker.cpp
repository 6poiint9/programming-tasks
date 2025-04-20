/* hier */

/* hier */ class Worker /* hier */
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string f_n, const string l_n, double h_e = 0.0, double h = 0.0) : Employee(f_n, l_n)
    {
        /* HIER */
    }

    double get_income() const
    {
        /* HIER */
    }

    void print() const
    {
        cout << "Worker: ";
        Employee::print();
    }
};