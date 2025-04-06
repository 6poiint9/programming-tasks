
#include <iostream>
#include <string>


class Customer {

    static int  _s_count;
    static int  _s_id_generator;
    std::string _name;
    std::string  _location;
    int         _age;
    double       _business_done;
    int         _transaction_count;
    int         _id;

  public:
    // mit konstrukter automatisch inkrementieren
    Customer(std::string name = "Unbekannt", int age = 0, std::string location = "Unbekannt") {
         _id = _s_id_generator;

        _age      = age;
        _location = location;
        _name     = name;


        // inkrement
        _s_count++;
        _s_id_generator++;
    }

    ~Customer() {
        _s_count—;
        // s_count dekremenent und id gleichlassen
    }
    void do_business(double amount) {
        _business_done += amount;
        _transaction_count++;
    }

    static int get_s_count() {
        return _s_count;
    }

    void print() {
        std::cout << "Kunde " << _name << " aus " << _location << " (ID = " << _id << ", " << _age << " Jahre) hatte " << _transaction_count << " Transaktion(en) und " << _business_done << " Euro Umsatz" << std::endl;
        
    }

}; 





