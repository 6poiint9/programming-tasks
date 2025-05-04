#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP 

#include <string>

class Account {
  private:
    std::string id;
    double balance; 
  public: 
    Account(const std::string &id, double bal);
    
    void deposit(double amount);
    void withdraw(double amount);
    
    double getbalance() const; 
    std::string getid() const; 
    
  
  void print() const; 
};

#endif 
