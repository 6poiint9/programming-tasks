#include <iostream>

using namespace std; 

int main()
{
  // variables for 2 integers and operator
  int a, b;
  char op;

  // Enter first number
  cout << "Enter First number: ", cin >> a;
  // enter operator
  cout << "Enter operator (+. -, *, /): ", cin >> op; 
  // Enter second number 
  cout << "Enter second number: ", cin >> b; 

  // calculate 
  switch (op) {
   case '+':
      cout << "Result: " << a + b;
      break;
    case '-':
      cout << "Result: " << a - b;
      break;
    case '*':
      cout << "Result: " << a * b;
      break;
    case '/':
      if (b == 0) {
        cout << "cannot divide by 0" << endl;  
      }
      else {
      cout << "Result: " << (float)a / b;
      }
      break;
    default:
      cout << "operator not recognized" << endl;
  } 

  return 0;
}

