#include <stdio.h>
// Funktion die überprüft ob eine genzzahl Primzahl ist oder nicht
// Ja = 1, Nein = 0

int prime(int a) {
  // o oder 1 
  int primcheck;
  // prüfen ob keine primzahl 
  if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
   // dann primcheck = 0
   primcheck = 0; 
  // keine primzahl
  else {
   // primcheck = 1
   primcheck = 1; 
  }

  // 0 oder 1 zurückgeben 
  return primcheck; 

}

// Ausgabe
/*
int main() 
{
 printf(prime(29) ? "Primzahl" : "KEINE Primzahl");
 return 0;
}
*/



