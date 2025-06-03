#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>
// => implement Store class + exeption class 
using namespace std;

// Hier Exception implementieren
class OutOfStockException : public std::exception {
private:
  int available_;
    int requested_;
public:
    OutOfStockException(int available, int requested)
        : available_(available), requested_(requested) {}

    const char* what() const noexcept override {
        cout << "Es sind " << available_ << " Artikel vom Typ Galaxy verfügbar. "
             << "Es können nicht " << requested_ << " Artikel verkauft werden." << endl;
        return "";
    }
};

// Hier Interface implementieren 
class ISubscriber {
public:
  virtual void update(string c) = 0;
  virtual ~ISubscriber() {} 
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
     cout << "Customer" << id << ": neue Nachricht verfügbar --> " << c << endl; 
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
    cout << "GoldCustomer" << id  << ": neue Nachricht verfügbar --> " << c << endl; 
  }
}; 

// Publisher -> Subject  
class Store {
private:
  list<ISubscriber *> _subscribers;
  map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};// state 
public:
  void subscribe(ISubscriber *s) {
    _subscribers.push_back(s); 
  }

  void unsubscribe(ISubscriber *s) {
    _subscribers.remove(s); 
  } 

  void notify_subscribers(const string& m) {
    for (auto sub : _subscribers) {
            sub->update(m);
        }
  }

  void deliver_products(const string &model, int qty) {
    cout << "Vorrätige Artikel vom Typ " << model << ": " << _product_availability[model] << endl;
        cout << "Ausgelieferte Artikel vom Typ " << model << ": " << qty << endl;
        _product_availability[model] += qty;
        cout << "Neuer Bestand: " << _product_availability[model] << endl;

        if (qty > 0 && _product_availability[model] == qty) {
            notify_subscribers("Neue Artikel vom Typ " + model + " verfügbar.");
        }
  }

  void sell_products(const string &model, int qty) {
    if (_product_availability[model] < qty) {
            throw OutOfStockException(_product_availability[model], qty);
        }

        if (_product_availability.find(model) != _product_availability.end()) {
            cout << "Vorrätige Artikel vom Typ " << model << ": " << _product_availability[model] << endl;
            cout << "Verkaufte Artikel vom Typ " << model << ": " << qty << endl;
            _product_availability[model] -= qty;
            cout << "Neuer Bestand: " << _product_availability[model] << endl;

            if (_product_availability[model] == 0) {
                notify_subscribers("Artikel vom Typ " + model + " nicht mehr verfügbar");
            }
        } else {
            cout << "Produkt nicht gefunden." << endl;
        }
    }
   
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


