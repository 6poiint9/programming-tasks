#include <stdio.h>
//  Potenz (a+b)^n soll für positive (int) n REKURSIV berechnet werden
int potenz(int c, int n); 

int main()
{
 int a, b, n;
 // user input
 scanf("%d %d %d", &a, &b, &n);
 int c = a + b; 
 //pass by value a b und c 
 int result = potenz(c, n);
 // ausgabe
 printf("%d", result); 

  return 0;
}

int potenz(int c, int n) {
  // Basis = c^0 ist immer 1
  if (n == 0) {
   return 1;
  }
  else {
  // c^n ist vorherige potenz mal c 
   return potenz(c, n-1) * c; 
  } 

 }
 




