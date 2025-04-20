#include <iostream>
#include "Worker.h"
#include "Manager.h"
//#include "Employee.h"

using namespace std;

int main()
{
    Manager m("Nabil","Yakoob", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;
    Worker w("Peter", "Mueller", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}
