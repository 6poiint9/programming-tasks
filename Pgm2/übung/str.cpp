#include <iostream>
#include <string>

using namespace std;
int main()
{
  string s1, s2 = "whatup";  
  
  cout << "enter s1: " << endl;
  cin >> s1; 
  
  short res = s1.compare(s2); 
  
  if (res == 0) {
    cout << "same" << endl;
  }
  else if (res < 0) {
    cout << "different" << endl; 
  }
  
  s1.append(" lul"); 
  cout << s1 << endl; 


  return 0; 
}
