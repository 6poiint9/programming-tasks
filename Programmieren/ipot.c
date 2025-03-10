/*
(a+b)^n soll iterativ berechnet werden

- a b n => durch nutzereingabe

Funktion:
iterative() =
- int return lsg 
*/ 
#include <stdio.h>

// Funtion prototypen
int iterate(int a, int b, int n); 

int main()
{
  // variablen declarieren
  int a, b, n; 
  // einlesen
  scanf("%d %d %d", &a, &b, &n);
  // pass by value
  int result = iterate(a, b, n); 
  // ausgabe ergebins
  printf("%d", result); 

  return 0; 
}

int iterate(int a, int b, int n) {
  // klammer addieren
  int ab = a + b;

  int summe = 1; 
  // potenzieren
  for (int i = 0; i < n; i++) {
    summe *= ab;  
  }
  
   return summe; 
}

