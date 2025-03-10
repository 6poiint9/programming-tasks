/*
(a+b)^n recursiv berechnen 

recursive() 
= 

 */
#include <stdio.h>

// Funktion prototyp
int recursive(int sum, int n); 

int main()
{
  // variablen deklarieren
  int a, b, n;
  // einlesen
  scanf("%d %d %d", &a, &b, &n); 
  // pass by value 
  int sum = a + b;
  int result = recursive(sum, n); 
  // ausgaeb resultat
  printf("%d", result); 

 return 0; 
}

int recursive(int sum, int n) {
  // recursion
  // Base => n 0 = 1, n 1 = abhome resonance
  if (n == 0) {
   return 1; 
  }
  else if (n == 1) {
   return sum; 
  }
  else {
    return sum * recursive(sum, n-1); 
  } 

}







