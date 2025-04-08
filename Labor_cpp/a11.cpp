#include <iostream>
#include <string>
using namespace std;

class A {
public:
	void method_1() {
		cout << "A::method_1()" << endl;
	}
	void method_2(double d) {
		cout << "A::method_2(double)" << endl;
	}
	void method_2(string s) {
		cout << "A::method_2(string)" << endl;
	}
	void method_3(char c) {
		cout << "A::method_3(char)" << endl;
	}
	void method_3(string s) {
		cout << "A::method_3(string)" << endl;
	}
};

class B : public A {
public:
	void method_2(int i) {
		cout << "B::method_2(int)" << endl;
	}
	void method_3(int i) {
		cout << "B::method_3(int)" << endl;
	}
	void method_3(string s) {
		cout << "B::method_3(string)" << endl;
	}
};

int main(int argc, char *argv[]) {
	A a;
	B b;
	cout << "a.method_1() ";
	a.method_1();		// a) keine Fehlermeldung;	b) Ausgabe: a.method_1(): A::method_1()
	cout << "b.method_1() ";
	b.method_1();	// keine Fehlermeldung  	
	cout << "a.method_2(1.2) ";
	a.method_2(1.2);	// a) kein fehler b) Ausgabe: A::method_2(double)
	cout << "b.method_2(1.2) ";
	b.method_2(1.2);	// a) kein fehler implizierte konv. b) Ausgabe B::method_2(int)
	cout << "a.method_2(1) ";
	a.method_2(1);		// a) kein fehler (implizierte) b) A: A::method_2(double) 
	cout << "b.method_2(1) ";
	b.method_2(1);	// a) kein fehler b) A: B::method_2(int)
	cout << "a.method_2('c') ";
	a.method_2('c');	// a) kein fehler b) A: A::method_2(string)
	cout << "b.method_2('c') ";
	b.method_2('c');	// a) kein fehler b) B::method_2(int) 
	cout << "a.method_2(''string'') ";
	a.method_2("string");	// a) kein fehler b) A::method_2(string)
	cout << "b.method_2(''string'') ";
	//b.method_2("string"); // a) fehler (string -> int nicht möglich )
	cout << "a.method_3(1) ";
	a.method_3(1); // a) kein fehler b) A::method_3(char)
	cout << "b.method_3(1) ";
	b.method_3(1);		// a) kein fehler b) B::method_3(int)
	cout << "a.method_3('c') ";
	a.method_3('c');	// kein fehler b) A::method_3(char)
	cout << "b.method_3('c') ";
	b.method_3('c');	// a) kein fehler b) B::method_3(int)
	cout << "a.method_3(''string'') ";
	a.method_3("string");	// a) kein fehler b) A::method_3(string)
	cout << "b.method_3(''string'') ";
	b.method_3("string");	// a) kein fehler b) B::method_3(string)
	return 0;
}

/*
c) 

i) 
void method_2(double d) überlädt void method_2(string s) 

ii) 
void method_2(int i) der klasse B verdeckt 	void method_2(double d) und void method_2(string s) 

iii)
	void method_3(string s) redifiniert 	void method_3(string s)

*/

