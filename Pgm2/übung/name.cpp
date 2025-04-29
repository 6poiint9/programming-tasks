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
