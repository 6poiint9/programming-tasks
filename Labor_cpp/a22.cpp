#include <string>
#include <ios>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
		cout << /* xxx */ << k;
		cout << /* xxx */ << k;
		cout << /* xxx */ << k << " ";
		cout << /* xxx */ <<  string(k % 5 + 1, '*')  << " ";
		cout << /* xxx */ << d;
		cout << /* xxx */ << d;
		d = d*-2;
		
		cout << endl;
	}
	return 0;
}

