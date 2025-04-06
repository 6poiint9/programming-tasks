#include <iostream>
#include <string>

class Customer {
 private:
  static int _s_count;  
  static int _s_id_generator;
  std::string _name;
  std::string _location;
  int _age;
  double _business_done = 0.0;
  int _transaction_count = 0; 
  int _id;

 public: 
  Customer(std::string n = "x", int a = 69, std::string l = "x") : _name{n}, _location{l}, _age{a} {
      _s_count++; // Increment customer count
      _id = ++_s_id_generator; // Assign unique ID       
  } 
  
  void do_business(double amount) {
    _business_done += amount;
    _transaction_count++; 
  }
  
  static int get_s_count() {
   return _s_count; 
  }
  
  void print() const {
    std::cout << "Kunde " << _name << " aus " << _location << " (ID = " << _id;
    std::cout << ", " << _age << " Jahre) " << "hatte " << _transaction_count;
    std::cout << " Transaktion(en) und " << _business_done << " Euro Umsatz" << std::endl; 
  } 


  ~ Customer() {
    _s_count--; // Decrement customer count
  }  

};

// Static variable definitions
int Customer::_s_count = 0;
int Customer::_s_id_generator = 0;

int main(int argc, char *argv[]) {
    
    Customer peter = Customer("Peter", 17, "Stuttgart");
	  Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
 	  Customer micheal = Customer("Michael", 21, "Karlsruhe");
	  Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}
