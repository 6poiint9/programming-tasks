#include <iostream>
#include <vector>
using namespace std;
// component-interface 
class IComponent {
public:
  virtual short get_price() const = 0; 
  virtual void add(IComponent *c) = 0;
}; 

// client 
void calculate_price(IComponent *component)
{
    cout << "Preis: " << component->get_price() << endl;
}

// leaf  
class Product : public IComponent {
private:
  short product; 

public:
  Product(short pr) 
    : product{pr} {} 
  
  short get_price() const override{
    return product; 
  }

  void add(IComponent* c) override {
    // Do nothing or throw, because leaf nodes can't have children
    cerr << "Cannot add to a product." << endl;
  }
}; 
// composite 
class Box : public IComponent{
private: 
  vector<IComponent*> products;
  short price; 
public:

  void add(IComponent *c) override{
    products.push_back(c); 
  }

  short get_price() const override {
    short total = 0; 
    for (auto& p : products) {
      total += p->get_price();   
    }
    return total;
  }

}; 
  
int main(int argc, char* argv[]) {

    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    calculate_price(product);
    cout << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    calculate_price(outer_box);
    cout << endl;
    
    cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl;

    return 0;
}


