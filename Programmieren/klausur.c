#include <stdio.h>

void func(int input, int a, int b) {
 if (input % 2 != 0 && input % 3 == 0 && input % 5 == 0) {
   a = 1;
   b = 0;
  }
 else {
   b = 1;
   a = 0; 
    }
}

int main() 
{
  int input;
  int a = 0;  // Initialize a to false (0)
  int b = 0;
  // a und b = false
  scanf("%d", &input);
  func(input, a, b);
  // var input
  printf("a = %d, b = %d\n", a, b);
  // input einlesen 
  
  
  return 0;
}
