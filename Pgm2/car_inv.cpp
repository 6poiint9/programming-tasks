#include <iostream>
#include <string>

using namespace std; 

// Class 
class car {
  // initialize variables as private 
 private:  
  string brand;
  int year;
  string color; 

 public:
  car() : brand{"Unknown"}, year{0}, color{"Not Assigned"} {}
  
  car(const string &b, int y, const string &c) : brand{b}, year{y}, color{c} {} 
  void display() const {
    cout << "Brand: " << brand << endl;
    cout << "Year: " << year << endl; 
    cout << "Color: " << color << endl; 
  }

}; 

int main() 
{
  car car1;
  cout << "Car 1: \n"; 
  car1.display(); 

  car car2("Toyota", 2022, "Blue"); 
  cout << "\nCar 2: \n"; 
  car2.display();

  return 0; 
}

