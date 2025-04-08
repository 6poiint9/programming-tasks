
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
	b.method_1();		
	cout << "a.method_2(1.2) ";
	a.method_2(1.2);	
	cout << "b.method_2(1.2) ";
	b.method_2(1.2);	
	cout << "a.method_2(1) ";
	a.method_2(1);		
	cout << "b.method_2(1) ";
	b.method_2(1);		
	cout << "a.method_2('c') ";
	a.method_2('c');	
	cout << "b.method_2('c') ";
	b.method_2('c');	
	cout << "a.method_2(''string'') ";
	a.method_2("string");	
	cout << "b.method_2(''string'') ";
	b.method_2("string"); 
	cout << "a.method_3(1) ";
	a.method_3(1);		
	cout << "b.method_3(1) ";
	b.method_3(1);		
	cout << "a.method_3('c') ";
	a.method_3('c');	
	cout << "b.method_3('c') ";
	b.method_3('c');	
	cout << "a.method_3(''string'') ";
	a.method_3("string");	
	cout << "b.method_3(''string'') ";
	b.method_3("string");	
	return 0;
}

