#include <stdio.h>
// Funktion die einen Fahrenheit-wert zu Celsius umrechnet

// Fahrenheit wert (f) als parameter
float celsius(float f) {
 // umrechnung
 float C = (f - 32.0) / 1.8; 
 // Wert in celsius zurückgeben 
 return C;
}

// Ausgabe 
/*
int main()
{
 printf("%dF = %.1fC", 20, celsius(20));
 return 0;
}
*/

