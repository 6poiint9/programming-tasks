#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
  std::vector<int> numbers = {2, 4, 6, 8, 10};
   
  // detailed declaration 
  for (auto it = std::begin(numbers); it != std::end(numbers); ++it) {
    std::cout << *it << " "; 
  }
  cout << endl; 
  // use const if not changing values 
  for (const auto& num : numbers) {
    cout << num << " "; 
  }
  cout << endl;
  // without const if wanting to change 
  for (auto& num : numbers) {
    num *= 2;
    cout << num << " "; 
  }
  
  int lol = 69; 
  numbers.push_back(lol); 

  cout << numbers.front() << " " << numbers.back() << endl;  
  
  cout << numbers.size() << endl;

  numbers.clear(); 

  cout << numbers.size() << endl; 

  std::stringstream ss; 

  ss << "Ich bin " << 19 << " Jahre alt und wiege " << 69.69 << " kg"; 

  std::string result = ss.str();

  cout << result << endl; 

  return 0;
}
