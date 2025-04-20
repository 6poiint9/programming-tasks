#include <iostream>
using namespace std;

 
class Point 
{ 
  private: 
   double _x, _y; 
  public: 
   Point() { 
  _x = 0; 
  _y = 0;  
  cout << "StandardKonstruktor von: " << _x << ", " << _y << endl;  }  
  Point(double x, double y) {
   this->_x = x; this->_y = y; 
   cout << "Konstruktor von: " << _x  << ", " << _y << endl; }  
  ~Point() {
    cout << "Desdtruktor von " << _x << ", " << _y << endl; }   
   double get_x() const { 
    return _x; } 
  double get_y() const { 
    return _y; } 
  void set_x(double x) { 
    this->_x = x; } 
  void set_y(double y) { 
    this->_y = y; } 
  void print() const {  
    cout << "x= " << _x << endl; cout << "y= " << _y << endl; } 
}; 

class Triangle 
{
  private:
    Point *p1, *p2, *p3;
  public:
   Triangle(double x1, double y1,  double x2, double y2,  double x3, double y3){
    : p1(x1, x2) {}
   }

}; 
