#include <iostream>
#include <string>
using namespace std;

void cell(string name, int value) {
	cout << "---------------------" << endl;
	cout << name << "= " << value << endl;
}

void search(string names[], int* p_values[], int n) {
	ios::fmtflags cout_flags = cout.flags();
	int i = 0, k = 0;
	string str = "";
	cout << hex << uppercase;

	while (i < n) {
		if ((i + k < n - 1) && (p_values[i + k] == p_values[i + k + 1])) {
			k++;
		} else {
			for (int m = i; m <= i + k; m++) {
				str += names[m] + " ";
			}
			cell(str, *p_values[i]);
			str = "";
			i += k + 1;
			k = 0;
		}
	}
	cout << "---------------------" << endl << endl;
	cout.flags(cout_flags);
}

//-------------------------------------------------
// Klassenhierarchie
class A {
public:
	int _a;
	A(int a = 0xA) : _a(a) {}
};

// A wird virtuell geerbt
class B : virtual public A {
public:
	int _b;
	B(int a = 0xD1A, int b = 0xB) : A(a), _b(b) {}
};

// B NICHT virtuell geerbt → eigene Instanz von B für C1
class C1 : public B {
public:
	C1(int a = 0xC1A, int b = 0xC1B)
		: B(a, b) {}
};

// B virtuell geerbt → gemeinsame Instanz mit C3
class C2 : virtual public B {
public:
	C2(int a = 0xC2A, int b = 0xC2B)
		: B(a, b) {}
};

// B virtuell geerbt → gemeinsame Instanz mit C2
class C3 : virtual public B {
public:
	C3(int a = 0xC3A, int b = 0xC3B)
		: B(a, b) {}
};

class D1 : public C2, public C3 {
public:
	D1(int c2_a = 0xD1C2A, int c3_a = 0xD1C3A,
		int c2_b = 0xD1C2B, int c3_b = 0xD1C3B)
		: A(0xD1A), B(0xD1A, 0xB), C2(c2_a, c2_b), C3(c3_a, c3_b) {}

	void print() {
		cout << "D1::print() ..." << endl;
		string names[] = { "C2::a", "C3::a", "C2::b", "C3::b" };
		int* p_values[] = { &(C2::_a), &(C3::_a), &(C2::_b), &(C3::_b) };
		search(names, p_values, 4);
	}
};

class D2 : public C1, public C2, public C3 {
public:
	D2(int c1_a = 0xD2C1A, int c2_a = 0xD2C2A, int c3_a = 0xD2C3A,
		int c1_b = 0xD2C1B, int c2_b = 0xD2C2B, int c3_b = 0xD2C3B)
		: A(0xA), B(0xA, 0xD2B), C1(c1_a, c1_b), C2(c2_a, c2_b), C3(c3_a, c3_b) {}

	void print() {
		cout << "D2::print() ..." << endl;
		string names[] = { "C1::a", "C2::a", "C3::a", "C1::b", "C2::b", "C3::b" };
		int* p_values[] = { &(C1::_a), &(C2::_a), &(C3::_a), &(C1::_b), &(C2::_b), &(C3::_b) };
		search(names, p_values, 6);
	}
};

int main(int argc, char *argv[]) {
	D1 d1_object;
	D2 d2_object;
	d1_object.print();
	d2_object.print();
	return 0;
}

