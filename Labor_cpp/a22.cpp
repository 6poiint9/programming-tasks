#include <string>
#include <iomanip> // setw()
#include <iostream> // right left 
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{                   
		cout << right << dec << setw(3) << k;
    cout << right << showbase << oct << setw(4) << k;
		cout << right << hex << nouppercase << setw(5) << k << " ";
		cout << setw(7) << left << setfill('+') << string(k % 5 + 1, '*') << " ";
		cout << right << fixed << setfill(' ') << setprecision(3) << showpos << internal << setw(9)<< d;
		cout << right << scientific << uppercase << noshowpos << setprecision(3) << setw(11) << d;
		d = d*-2;  
		
		cout << endl;
	}
	return 0;
}

