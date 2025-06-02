#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>
// => implement Store class + exeption class 
using namespace std;

// Hier Exception implementieren
class Myexception : public std::exception {
private:
  string message; 
public:
  //Myexception
};

// Hier Interface implementieren 
class ISubscriber {
public:
  virtual void update(string c) = 0; 
}; 

// Hier Klassen Customer und GoldCustomer implementieren
// => 2 concrete subscribers 

class Customer : public ISubscriber {
private:
  static int _id_generator;
  int id; 
public:
  Customer() {
    id = ++_id_generator;
  } 

  void update(string c) override {
     cout << "Customer" << id << c << endl; 
  }
};

class GoldCustomer : public ISubscriber {
private:
  static int _id_generator; 
  int id; 
public:
   GoldCustomer() {
    id = ++_id_generator;
   }

   void update(string c) override {
    cout << "GoldCustomer" << id << c << endl; 
  }
}; 

// Publisher 
class Store {
private:
  list<ISubscriber *> _subscribers;
  map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};// state 
public:
  void subscribe(ISubscriber *s);

  void unsubscribe(ISubscriber *s); 

  void notify_subscribers(); 

  void deliver_products(string p, int quantity); 

  void sell_products(string p, int quantity); 
};


int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

void manage_store()
{
    try
    {
        Store *store = new Store;
        ISubscriber *customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber *customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber *customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber *customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber *customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char *argv[])
{
    manage_store();
    return 0;
}


