/*
Klasse implementieren:

- Methode print()

- getter- und setter-Methoden für x und y,
*/
#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren
class Point {
  private:
   short x;
   float y;

  public:
   // setter methoden 
   void set_x(int x_input) {
    x = x_input; 
   }
   void set_y(float y_input) {
    y = y_input; 
   }
   // getter methoden
   int get_x() const {
    return x; 
   }
   float get_y() const {
    return y;
   }
  // print methode
  void print() const {
    cout << "print-Methode:\n"; 
    cout << "X = " << x << endl; 
    cout << "Y = " << y << endl; 
  }
}; 


int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
 
