/*
Class vector:
-> represent a 2d vector with x and y components

overload:
- the + operator to add 2 vectors 

- the * operator to multiply 
*/
#include <iostream>

//short g_multiplier; 

class Vector {
 private:
  short x, y;
 public:
  Vector() : x{0}, y{0} {} // initialize with 0 
  Vector(const short &x, const short &y) : x{x}, y{y} {}

  Vector operator + (const Vector &other) const {
   Vector sum;
   sum.x = x + other.x;
   sum.y = y + other.y;
   
   return sum; 
  }

  Vector operator * (const short other) const {
    Vector product;
    product.x = x * other;
    product.y = y * other;

    return product;
  }

  void display_sum() const {
    std::cout << "Result of v1 + v2: (" << x << ", "<< y << ")" << std::endl; 
  }
  void display_product(const short multiplier) const {
    std::cout << "Result of v1 * " << multiplier << ": (" << x << ", "<< y;
    std::cout << ")" << std::endl; 
  }
};

int main()
{
  Vector v1(4, 6); 
  Vector v2(3, 2);
  
  short multiplier = 3; 
  
  Vector sum = v1 + v2;
  
  Vector prod = v1 * multiplier; 
   
  sum.display_sum(); 

  prod.display_product(multiplier);

  return 0;
}

