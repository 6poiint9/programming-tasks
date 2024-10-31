#include <stdio.h>
// Funktion die den Flächeninhalt eines Dreiecks berechnet

// grundseite (g) und höhe (h) als parameter 
float triangleArea(float g, float h) {
 
 // Formel F
 float F = 0.5 * g * h; 
 // Flächeninhalt zurückgeben 
 return F;
}

// Ausgabe
/*
int main()
{
  printf("%.2f", triangleArea(3, 4));
  return 0;
}
*/

