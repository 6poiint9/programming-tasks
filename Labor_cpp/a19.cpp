#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Meal {
public:
  virtual void add_topping(string top) = 0;

  virtual void prepare() const = 0; 
  
  virtual ~Meal() = default;  
}; 

class Pizza : public Meal {
private: 
  string pizza_art; 
vector<string> topping_list;
public:
  Pizza(string art) 
    : pizza_art{art} {}
  
  void add_topping(string top) override {
    topping_list.push_back(top); 
  } 

  void prepare() const override {
    cout << "Pizza " << pizza_art << ". Pizzaboden, belegt mit:" << endl; 
    for (auto& t : topping_list) {
      cout << "- " << t << endl; 
    }
  } 
  
};

class Burger : public Meal {
private: 
  string burger_art; 
  vector<string> topping_list;
public:
  Burger(string art) 
    : burger_art{art} {}
  
  void add_topping(string top) override {
    topping_list.push_back(top); 
  } 

  void prepare() const override {
    cout << burger_art << ". " <<"Brötchen mit:" << endl; 
    for (auto& t : topping_list) {
      cout << "- " << t << endl; 
    }
  }
}; 




int main(int argc, char* argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}

