/*
2 Classes:

- Address 

- Employee
-> contains Address object
*/

#include <iostream>
#include <string>
#include <unistd.h> 

class Address {
  private:
    std::string street;
    std::string city; 
    short zipcode;
  public:
    Address(std::string str, std::string cit, short zip) 
     : street{str}, city{cit}, zipcode{zip} {}
   
    void print() const {
      std::cout << street << ", " << city << ", " << zipcode << std::endl; 
    }
}; 

class Employee {
  private:
    std::string f_name;
    std::string l_name;
    Address obj; 
  public:
    Employee(std::string fn, std::string ln, std::string str, std::string cit, short zip) 
     : f_name{fn}, l_name{ln}, obj{str, cit, zip} {}     
      
    void print() const {
      std::cout << "Name: " << f_name << " " << l_name << std::endl; 
      obj.print();  
    }
};

std::tuple<std::string, std::string>getname();  

std::tuple<std::string, std::string, short>getaddr();  

int main() 
{
  std::string street, city, fname, lname;
  short zipcode;
  char option; 
  do {
   std::cout << "Hey want do add some personal info?" << std::endl;
   std::cout << "Press Y to add, P to print and X to exit!" << std::endl;
   std::cout << "You have to add min. 1 person in order to print (P)" <<
   std::endl;  
   sleep(2); 
   std::cout << "Enter option: " << std::endl;  
   std::cin >> option; 
   
  switch (option) {
        case 'Y':
            std::tie(fname, lname) = getname();
            std::tie(street, city, zipcode) = getaddr();
            break;

        case 'P':
        {
            Employee obj(fname, lname, street, city, zipcode);
            obj.print();
            break;
        } 
        case 'X':
            std::cout << "Exiting...\n";
            sleep(1);  // Sleep for 1 second (for Unix-like systems)
            break;

        default:
            std::cout << "Invalid option\n";
            break;
    } 
  }
  while(option != 'X'); 



  return 0;
}

using namespace std;

std::tuple<std::string, std::string>getname() {
  string fname, lname; 
  
  std::cin.ignore(); 

  cout << "Enter first name: " << endl;
  getline(cin, fname); 
  
  //std::cin.ignore(); 

  cout << "Enter last name: " << endl;
  cin >> lname; 
  
  return {fname, lname}; 
} 

std::tuple<std::string, std::string, short>getaddr() {
  string str, cit;
  short zip; 
  
  std::cin.ignore(); 

  cout << "Enter street name: " << endl;
  getline(cin, str); 
  
  //std::cin.ignore();

  cout << "Enter city: " << endl; 
  cin >> cit; 

  cout << "Enter zipcode: " << endl; 
  cin >> zip; 

  return {str, cit, zip}; 

}






