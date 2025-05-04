/*
#include <iostream>
using namespace std;

// create a namespace with a double variable
namespace db1 {
    double var = 98.0;  
}

namespace db2 {
   double var = 66; 
}
using namespace db2;
int main() {
    
    // create an int variable of the same name
    //int var = 5;
    
    int cout = 88; 
        // use the created namespace to avoid naming conflict
    //dbl::var = 5.55;
    
    // display the variables
     
  std::cout << "dbl var = " << var << endl;
  std::cout << "main var = " << var << endl;
  std::cout << "dbl var = " << db2::var << endl;
    
  std::cout << cout << endl;
  
    return 0;
}
*/
#include <iostream>

class Base {
public:
    void show(int x) { std::cout << "Base show\n"; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived show\n"; }
};

int main() {
    Derived d;
    d.show();       // OK: calls Derived::show()
    d.Base::show(5);  // ❌ error: Base::show is hidden by Derived::show()

    std::cout << __DATE__ << std::endl; 
}











