/*
 University Management System

=> keep track of Students, Proffessors and courses

Functionality

- Add Students and Proffessors

- Assign Proffessors to courses 

- Enrolling students in courses

- Displaying information about students, professors, and courses

- Remove Students 
*/
#include <iostream>
#include <string>

using namespace std; 

// University class 
// 

// Has-a relationship

// Base class Person 

class Person {
  protected:
   string name;
   short age; 
   string id; 
  public:
   Person(const string &n = "x", const short a = 0, const string &id = "x") : name{n}, age{a}, id{id} {} 
     
  
};

// Derived classes:
// => multiple inheritance 

// Professor
class Professor : public Person {
  private:
  // dynmic array 
   Person **person;  
  // alocate memory
  public:
   
};
// Student
class Student : public Person {
  public:
   // function to enter Student details
};

// Course class
// => Has-a relationship -> composition

tuple<string, string, string> get_prof_values();
tuple<string, string, string> get_stud_values();

int main()
{
  Student s1;
  Professor p1; 

  string a, b, c;
  
  // Assign the values
  tie(a, b, c) = get_prof_values(); 
 // p1.pro

  return 0;
}

tuple<string, string, string> get_prof_values() {
 
  string n, a, id; 
  cout << "\nEnter professor details:"; 
  cout << "Name: ";
  cin >> n; 
  cout << "Age: ";
  cin >> a; 
  cout << "Professor ID: ";
  cin >> id; 

  return {n, a, id}; 
  
} 

tuple<string, string, string> get_stud_values() {}







