// program to divide two numbers
// throws an exception when the divisor is 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
  double a, b, divide; 

  cout << "Enter a: " << endl;
  cin >> a;

  cout << "Enter b: " << endl;
  cin >> b;

  double arr[4] = {0.0, 0.0, 0.0, 0.0};
  int index;

  int length = sizeof(arr) / sizeof(arr[0]);
 
  cout << "Enter array index: ";
  cin >> index;

  try {
    
    if (b == 0) { throw 0; } 
    
    if (index > length) {throw "outside bounds!";} 

    divide = a / b; 
    cout << a << " / " << b << " = " << divide << endl;

    arr[index] = divide; 

  }
  catch ( string num_ex) {
    cout << "divided by 0 !" << endl; 
  }
  catch (int str_ex) {
    cout << "index outside bounds!" << endl; 
  }
   
  for (int i = 0; i < length; i++) {
    cout << i + 1 << ". " << arr[i] << endl; 
  }
  return 0;
}


