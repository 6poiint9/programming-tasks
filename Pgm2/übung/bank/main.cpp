#include "customer.hpp"

//#include <iostream>

int main()
{
  Customer c1("M10198", 69000.0, "Ben Pitter"); 

  c1.deposit(690.0); 
  c1.print(); 

  c1.withdraw(100000.0); 
  c1.print();
  
  Customer c2("M12984", 138233.62, "Louis Hall"); 
  /*
  if (c1 == c2) {
    std::cout << "Same account!" << std::endl; 
  } 
  else {
    std::cout << "Accounts are different!" << std::endl; 
  }
  */
  return 0;
}



