#include <iostream>
#include <string>

using namespace std; 

class Product {
  public:
   string name; 
   string price;
   short quantity; 

  Product(const string &n = "", const string &p = "", short q = 0) : name{n}, price{p}, quantity{q} {} 

  void display () const {
    cout << " " << name << " - " << price << " x " << quantity;  
  }

}; 

// "Has - a" relationship -> Cart has product 
class Cart {
  private:
   Product **products; // Dynamic array of type class 
   short count;
   short capacity; 
  /*
   allocate memory - add - display - remove - destructor
  */
  public:
  // Defaulted constuctor to allocate memory 
   Cart(short cap = 15) : capacity{cap}, count{0} { // set size to allocate + initialize count
    products = new Product*[capacity];  // allocate
  }   
   
  void add(const string &n, const string &p, short q) {
    // check if capacity max 
    if (count < capacity) {
      // allocate memory and call constructor to initialize values
      products[count++] = new Product(n, p, q); 
      cout << "✅ Product added successfully!"; 
    }
  }
  
  void displayCart() const {
    // check if cart empty 
    if (count == 0) {
      cout << "cart is empty"; 
      return; 
    }
    else {
      cout << "\n 🛍️ Shopping Cart:\n"; 
      for (int i = 0; i < count; i++) {
        cout << i + 1 << ". "; 
        products[i]->display(); 
      } 
    }
  }

  void remove(int index) {
    if (count == 0) {
      cout << "Nothing to remove, cart is empty!"; 
      return;
    }

    if (index < 1 || index > count) {
      cout << "Invalid product number!\n"; 
      return;
    }
    else {
      for (int i = index - 1; i < count - 1; i++) {
        products[i] = products[i + 1]; 
      }
      count--; 
      cout << "✅ Product removed!\n";
    }
  }

  ~Cart () {
    // Loop through and delete items 
    for (int i = 0; i < count; i++) {
      delete products[i]; // delete single items
    }
    delete[] products; // delete array itself
  } 
   
}; 


int main()
{

  return 0;
}















