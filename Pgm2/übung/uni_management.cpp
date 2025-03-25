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

class Person { // Base class 
  protected:
   string name;
   short age; 
   string id; 
  public:
  // default constructor to assign stuff  
   Person(const string &n, short a, const string &id) : name{n}, age{a}, id{id} {} 
   
   // Virtual function to display details 
   virtual void display() const {
     cout << "\nPeople: ";
     cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << endl; 
   }
   // frees derived class functions before base 
   virtual ~Person() {} 
};

// Derived classes: 

class Professor : public Person {
  private:
   string fac;
   //Person **people; 

  // alocate memory
  public:
  // constructor
   Professor(const string &n, short a, const string &id, const string &fac) 
    : Person{n, a, id}, fac{fac} {} 
  // display function 
   void display() const override {
   cout << "\nProfessors: "; 
   cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << "\nFaculty: " << fac << endl; 
   }  
};

class Student : public Person {
  private:
   string gpa; 
   string major;

  public:
   // constructor to initialize values 
   Student(const string &n, short a, const string &id, const string &g, const string &m) 
    : Person{n, a, id}, gpa{g}, major{m} {}  
  // display function
   void display() const override {
    cout << "\nStudents:"; 
    cout << "\nName: " << name << "\nAge: " << age << "\nID: " << id << "\nGPA: " << gpa << "\nMajor: " << major << endl;  
   }
};

// -----

class University {
 private:
  short capacity; // to prevent memory missuse 
  short count; // total number, number student/profs 
  Person **people; // dynamic array
 public:
  // First initialize and allocate memory
  // max 15 student and 2 professors
  University(short cap = 17) : capacity{cap}, count{0} {
   people = new Person*[capacity]; // allocate memory for the array of 17 people 
  }
  // => have the structure to manage multiple people  
  
  // Add people:

   void add_prof(const string &n, short a, const string &id, const string &fac) {
    // check if space left
    if (count > capacity) {
      cout << "Uni is full!\n";
      return; 
    }
    else {
     // add and allocate memory for the values of an individual person/object 
     people[count++] = new Professor(n, a, id, fac); 
     cout << "Professor added ✅"; 
    }
   }
   
   void add_student(const string &n, short a, const string &id, const string &g, const string &m) {
    // check if space left
    if (count > capacity) {
      cout << "Uni is full!\n";
      return; 
    }
    else {
     // add and allocate memory for the values of an individual person/object 
     people[count++] = new Student(n, a, id, g, m); 
     cout << "Student added ✅"; 
    } 
   }

/*
  // Remove people by ID: 
  void remove(short id) {
   // check if list empty 
   if (count == 0) {
    cout << "Uni is empty :("; 
    return; 
   }
   else {
    while (id != )
    for (int i = 0; i < count; i++) {
          
    }   
   }
  }
*/

  
  // Destructor 
};


// Course class
// => Has-a relationship -> composition

tuple<string, short, string, string> get_prof_values();
tuple<string, short, string, string, string> get_stud_values();

int main()
{
  string name, id, fac, gpa, major;
  short age;
  // Tie Prof values
  tie(name, age, id, fac) = get_prof_values(); 
  Professor p1(name, age, id, fac); 
 // Tie Student values 
  tie(name, age, id, gpa, major) = get_stud_values(); 
  Student s1(name, age, id, gpa, major);
    
  p1.display();
  s1.display(); 

  return 0;
}

tuple<string, short, string, string> get_prof_values() {
  short a;
  string n, id, f; 
  cout << "\nEnter professor details:\n"; 
  cout << "Name: ";
  getline(cin ,n); 
  cout << "Age: ";
  cin >> a; 
  cout << "Professor ID: ";
  cin >> id;
  cout << "Faculty: ";
  cin >> f; 

  return {n, a, id, f}; 
  
} 

tuple<string, short, string, string, string> get_stud_values() {
  short a;
  string n, id, gpa, m;  
  cout << "\nEnter student details:\n";
  cout << "Name: ";
  cin.ignore(); 
  getline(cin ,n); 
  cout << "Age: ";
  cin >> a; 
  cout << "Student ID: ";
  cin >> id; 
  cout << "GPA: ";
  cin >> gpa; 
  cout << "Major: ";
  cin >> m; 
  
  return {n, a, id, gpa, m}; 
  
}






