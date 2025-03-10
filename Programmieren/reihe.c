/*
reihe mit länge n recursiv berechnen

y = (a + 2*x) + ...

=> (a + 2*n*x) 

Funktionen:
input();
recursion(); 
 */
#include <stdio.h>

float recursion(float a, float x, int n); 

int main()
{
   
 float a, x;
 int n;
 scanf("%f %f %d", &a, &x, &n); 

 float result = recursion(a, x, n); 
  
  printf("%.1f", result);

  return 0; 
}

float recursion(float a, float x, int n) {
 if (n == 0) {
  return 0; 
 } 
 else {
  return (a + 2 * n * x) + recursion(a, x, n - 1); 
 }

}







