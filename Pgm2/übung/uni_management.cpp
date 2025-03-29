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
  // Virtual function to get id  
   virtual string get_id() const {
    return id; 
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
  
  // get id 
   string get_id() const override {
    return id;  
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
  
  // get id 
   string get_id() const override {
    return id;  
   }
};

// -----

class University {
 private:
  short capacity; // to prevent memory missuse 
  short count; // total number, number student/profs 
  Person **people; // dynamic array
  //University *next; 
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


  // Remove people by ID: 
  void remove(string id) {
   bool found = false; 
   // check if list empty -> base case 
   if (count == 0) {
    cout << "Uni ist empty !";
    return; 
   }
   // traverse the array and c
   for (int i = 0; i < count; i++) {
    if (people[i]->get_id() == id)  {
      // delete + re-arrange array
      delete people[i]; 
      for (int j = i; j < count - 1; j++) { // i -> starting point 
              people[j] = people[j + 1];
      }

      // Clear the last element 
      people[count - 1] = nullptr;

      count--; // decrease count  
      cout << "Person removed :)";
      found = true;

      break; // -> found person 
    }
   }
   if (!found) {
    cout << "could not find the id"; 
   } 
  } 

  // display
  void display() {
    // check if list empty
    if (count == 0) {
      cout << "Uni is empty :("; 
      return;
    }
    else {
      for (int i = 0; i < count; i++) {
        people[i]->display(); 
      }
    }
  }
  
  // Destructor
  ~University() {
    for (int i = 0; i < count; i++) {
      delete people[i]; 
    }
    delete[] people; // Deallocate the array itself
  }
};

// head pointer 
University *head = nullptr; 

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
  University p1;  
  p1.add_prof(name, age, id, fac); 
 // Tie Student values 
  tie(name, age, id, gpa, major) = get_stud_values(); 
  //Student s1(name, age, id, gpa, major);
  

  return 0;
}

void interact() {
  string ex;
  char option;
  do {
   cout << "\nWelcome to the University management system!\n";
   cout << "Options:";
   cout << "- Type 'exit' to end the program"; 
   cout << "- Press 1 to add Professor";
   cout << "- Press 2 to add a student";
   cout << "- Press 3 to display the University members";
   cout << "- Press 4 to remove a memeber by ID";
   cout << "\nEnter option: "; 
   cin >> option;
   while (option < 1 || option > 4) {
    cout << "Please re-enter a valid option!";
    cin >> option; 
   }
   // conditionals
   switch (option) {
     case '1': 
      get_prof_values(); 

      
   }
   
  }
  while (ex != "exit");

  
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






