#include <stdio.h>
//  Potenz (a+b)^n soll für positive (int) n ITERATIV berechnet werden
int potenz(int a, int b, int n); 

int main()
{
 int a, b, n;
 // user input
 scanf("%d %d %d", &a, &b, &n); 
 //pass by value a b und c 
 int result = potenz(a, b, n);
 // ausgabe
 printf("%d", result); 

  return 0;
}

int potenz(int a, int b, int n) {
 int c = a + b;
 // res = 1 wegen mal und 5^1 
 int res = 1; 
 for (int i = 0; i < n; i++) {
 // potenzieren 
  res *= c;
 }
 return res; 
}



