#include <iostream>

using namespace std;

class Point {
 private:
  double _y, _x; 
 public: 
  Point(double y = 0.0, double x = 0.0) : _y{y}, _x{x} {}

  void set_y(double y) {
    _y = y; 
  }

  void set_x(double x) {
    _x = x; 
  }

  double get_y() const {
    return _y; 
  } 

  double get_x() const {
    return _x; 
  }

  void move(double dx, double dy) {
    _x += dx; 
    _y += dy; 
  } 

  void print(bool b = true) const {
   if (b) {
   cout << "(" << _x << ", " << _y << ")" << endl;
   }
   else {
    cout << "(" << _x << ", " << _y << ")";
    } 
  }
};

class Circle {
 private:
  Point _centre; 
  double _radius = 1.0; 
 public: 
  Circle(Point p) : _centre{p} {} 
  
  void set_centre(Point p) {
    _centre = p; 
  }

  void set_radius(double r) {
    _radius = r; 
  }

  Point get_centre() const {
    return _centre; 
  }
  
  double get_radius() const {
    return _radius;
  }

  void move(double dx, double dy) {
   _centre.move(dx, dy); 
  }
  
  void print(bool b = true) const {
   if (b) {
    cout << "[(" << _centre.get_x() << ", " << _centre.get_y() << "), " << _radius << "]" << endl;
   }
   else {
    cout << "[(" << _centre.get_x() << ", " << _centre.get_y() << "), " << _radius << "]";
   }
  }
};

int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_centre(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}






