#include <iostream>
#include <string>

using namespace std;

class Person {
	protected:
  string _name;
	int _check_out_duration;
public:
	Person(string name, int check_out_duration = 0) :
  _name{name}, _check_out_duration{check_out_duration} {}

	int get_check_out_duration() const {
    return _check_out_duration; 
  } 

	virtual void print() const {
   cout << "Name: " << _name << ", Ausleihdauer: " << _check_out_duration << " Tage(e)" << endl;
  }
};

// Implmentierung des Konstruktors und der Methoden

class Lecturer : public Person 
{
private:  
	int _examiner_id;
  
public: 
	Lecturer(string name, int e_id, int check_out_duration = 90) : Person{name, check_out_duration}, _examiner_id{e_id} {}  
	
  void print() const override { 
   cout << _name << ", Prüfernummer " << _examiner_id << endl; 
  }
};

// Implmentierung des Konstruktors und der Methoden

class Student : public Person 
{
private:
	int _matriculation_number;
   
public:
	Student(string name, int m_num, int check_out_duration = 30) : Person{name, check_out_duration}, _matriculation_number{m_num} {} 
	
  void print() const override {
    cout << _name << ", Matrikelnummer " << _matriculation_number << endl;   
  }
};


// Implmentierung des Konstruktors und der Methoden

int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

