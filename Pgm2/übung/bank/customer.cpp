#include "customer.hpp"
#include "account.hpp"

#include <iostream>
#include <string>
    
  Customer::Customer(const std::string &id, double bal, const std::string &nam)   : acc{id, bal}, name{nam} {}   
  
  void Customer::deposit(double amount) {
    acc.deposit(amount);    
  }
  void Customer::withdraw(double amount) {
    acc.withdraw(amount); 
  }
  
  void Customer::print() const {
    std::cout << "Name: " << name << std::endl; 
    acc.print(); 
  }


