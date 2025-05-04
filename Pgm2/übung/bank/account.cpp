#include "account.hpp"

#include <iostream>
#include <ostream>
#include <string>

    std::string id;
    double balance;

     Account::Account(const std::string &id, double bal)
     : id{id}, balance{bal} {} 
    
    void Account::deposit(double amount){
      balance += amount; 
    }
    void Account::withdraw(double amount){
      balance -= amount; 
    }
    
    double Account::getbalance() const {
      return balance; 
    }
    std::string Account::getid() const {
      return id; 
    } 
    
    void Account::print() const {
      std::cout << "ID: " << id << std::endl; 
      std::cout << "Balance: " << balance << "$" << std::endl; 
    }      
    
