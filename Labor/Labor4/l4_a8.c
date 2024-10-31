#include <stdio.h>
#include <math.h>
// Funktion die den Bmi berechnet 

// Gewicht (g) und Körpergröße (h) in cm als Parameter 
float bmi(float g, float h) {
 // Umrechnung cm in m 
 float hkg = h / 100; 
 // Bmi Formel F
 float F = g / pow(hkg, 2);  
 
 return F;
}

// Ausgabe 

int main() 
{
 printf("%dkg und %fm = %.2lf", 85, 1.5, bmi(85, 150));  
 return 0;
}

