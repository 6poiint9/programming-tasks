#include <iostream>
//#include <string>

using namespace std; 

struct bio {
  string firstname;
  string lastname;
  int age;
  char gender; 
  
  void printbio() {
    cout << "First name: " << firstname << endl; 
    cout << "Last name: " << lastname << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age : " << age << endl;
  }

}; 

int main()
{
  bio p1 = {"Mark", "Goldbridge", 69, 'M'}; 

  cout << "Person 1: \n"; 

  p1.printbio(); 

  return 0;
}

