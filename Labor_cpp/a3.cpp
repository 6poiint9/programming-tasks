/*
eine matrix mit X-char drucken je nach parameter 
*/

#include <iostream>

using namespace std;

// 
void print_rectangle(short breite = 4, short höhe = 4); 

int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

	std::cout << "x = 4: " << std::endl;
	print_rectangle(4);

	return 0;
}; 

void print_rectangle(short breite,short höhe) {
  // nested for loop um zu drucken
  for (int i = 0; i < höhe; ++i) {
   for (int j = 0; j < breite; ++j) {
     cout << 'x' << ' '; 
   } 
   cout << endl; 
  }
 cout << endl; 
}
