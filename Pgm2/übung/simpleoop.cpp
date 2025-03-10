#include <iostream>
#include <string>

using namespace std; 

class car {
 private:
  string brand; 
  string model;
  string year;
  int i;
  int y;
  int z = 404;

 public:
  
  //car() = default; 

  car(const string yr, int i, int s) : year{yr}, i{i}, y{s}  {
    cout << "Minimum Year is " << year << endl;
    cout << "Some nums: " << i << " " << y << endl;
    cout << z << endl; 
  }

  car(const car &obj) : year{obj.year} {} 

  void setDetails(const string b, const string m, const string y) {
    brand = b;
    model = m;
    year = y; 
  }
  void displayDetails() {
   cout << "Brand: " << brand << endl; 
   cout << "Model: " << model << endl; 
   cout << "Year: " << year << endl; 
  } 

};

int main() 
{
 car mycar("1999", 101, 361);  
 //car mycar1; 
 
 car mycar2 = mycar; 

 mycar.setDetails("BMW", "X7", "2024"); 

 mycar.displayDetails(); 
 
 



 return 0; 
}
