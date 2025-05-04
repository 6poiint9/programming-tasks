#ifndef BANK_CUSTOMER_HPP
#define BANK_CUSTOMER_HPP

#include "account.hpp"
#include <string>

class Customer {
  private:
   Account acc; 
   std::string name; 
  public: 
    Customer(const std::string &id, double bal, const std::string &nam); 
    
    void deposit(double amount);  
    void withdraw(double amount);
    
    void print() const; 
};



#endif // BANK_CUSTOMER_HPP





