#include <iostream>
#include <unistd.h>
#include <string>

using namespace std; 

int main() 
{
  // print char/strings
  cout << "hello :)" << endl; 
  sleep(3); 
  // print numbers 
  cout << "hey!" << endl;

  string var = "nice"; 
  
  cout << var << endl; 

  return 0;
}
