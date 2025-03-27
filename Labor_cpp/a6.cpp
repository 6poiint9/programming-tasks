#include <iostream>
#include <string>

class Student 
{
 private:
  std::string _name, _first_name;
 public:
  // construktor 
  Student(const std::string &name, const std::string &f_name) {
    _name = name;
    _first_name = f_name;
    // Ausgabe 
   std::cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << std::endl;    
  } 
  
  // getter funktionen
  std::string get_name() const {
    return _name; 
  }

  std::string get_fname() const {
    return _first_name; 
  }
  
  // display functions 
  void print(bool choose) const {
   if (choose) {
    std::cout << "print() mit Parameter; Student: " <<_first_name << " " << _name << std::endl;   
    }
   else {
    std::cout << "print() mit Parameter; Student: " <<_first_name << " " << _name;    
    }
   }
   
   void print() const {
    std::cout << "print() ohne Parameter; Student: " << _first_name << " " << _name << std::endl; 
   }
   
   ~Student() {
    std::cout << "Destruktor Student: " << _first_name << " " << _name << std::endl; 
   } 
}; 

class Employee 
{
 private:
  std::string _first_name, _name; 
 public:
  Employee(const std::string &f_name, const std::string &name) 
  : _first_name{f_name}, _name{name} {
  std::cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << std::endl; 
  } 

  Employee() : _first_name{"Erika"}, _name{"Mustermann"} {
    std::cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << std::endl;  
  }

  Employee(const Student &s) : _first_name{s.get_fname()}, _name{s.get_name()} { 
   std::cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << std::endl; 
  } 

  // print methoden 
  void print(bool choose) const {
   if (choose) {
    std::cout << _first_name << "\n" << _name << std::endl;   
    }
   else {
    std::cout << _first_name << " " << _name << std::endl;    
    }
   }
   
   void print() const {
    std::cout << "print() ohne Parameter; Mitarbeiter:" << _first_name << " " << _name << std::endl; 
   }

   ~Employee() {
     std::cout << "Destruktor Employee: " << _first_name << " " << _name << std::endl; 
    }

};



int main(int argc, char *argv[])
{
    Student stud_mustermann("Mustermann", "Max");
    Employee empl_mustermann = Employee(stud_mustermann);
    Employee mit_default = Employee();
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    std::cout << "Block wird betreten" << std::endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    std::cout << "Block wurde verlassen" << std::endl;
    delete p_stud_mustermann;
    return 0;
}
