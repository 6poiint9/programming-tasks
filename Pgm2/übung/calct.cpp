#include <iostream>
#include <tuple>
using namespace std;

template <typename T>
class Calculator {
  private:
    T num1, num2, res; 
  public:
    Calculator(T n1, T n2, T res = 0) 
      : num1{n1}, num2{n2}, res{res}{}
   
    // could of just used a bunch of void functions
    // instead to just print out result
    T add() {
     res = num1 + num2; 
      return res;
    }

    T sub() {
     res = num1 - num2;
      return res; 
    }
    
    T mul() {
      res = num1 * num2; 
      return res; 
    }

    T div() {
      switch (num2) {  
        case 0: 
          cout << "Cannot divide by 0!" << endl;
          break; 
        default:
          res = num1 / num2;     
      }
      return res; 
    }    
    
    void print() const {
      cout << "The result is = " << res << endl; 
    }
}; 

tuple<short, short> getnums(); 

int main()
{
  short n1, n2; 
  char opt; 

  tie(n1, n2) = getnums(); 

  Calculator<short> calc(n1, n2);  
  
  cout << "What operation to do ? Options: + , - , / , * : " << endl; 
  cin >> opt; 

  switch (opt) {
    case '+': 
      calc.add(); 
      calc.print();
      break;
    case '-':
      calc.sub();
      calc.print();
      break;
    case '*':
      calc.mul();
      calc.print();
      break;
    case '/':
      calc.div();
      calc.print();
      break;
    default: 
      cout << "unrecognized option"; 
  }

  return 0;
}

tuple<short, short> getnums() {
  short n1, n2; 

  cout << "Please enter first number: " << endl; 
  cin >> n1; 

  cout << "Please enter second number: " << endl; 
  cin >> n2; 

  return {n1, n2}; 
} 













