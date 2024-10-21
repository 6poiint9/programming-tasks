#include <stdio.h>
// Eine temperaturtabelle mit Fahrenheit links und Celsius rechts, ohne user input
// 20-er schritte vom -20 bis 300 -> Celsius in float  

int main() {
  // Temperatur Einheit
  printf("Fahrenheit      Celsius\n"); 
  // array für die Fahrenheit werte
  int fahrenheitWerte[] = {-20, 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
  // Umrechnung in schleife
  for (int cf = 0; cf < 17; cf++) {
    printf("%10d", fahrenheitWerte[cf]);
    // umrechnung von Fahrenheit zu Celsius  
    double celsiusWerte = (fahrenheitWerte[cf] - 32.0) * 5.0 / 9.0;
    printf("%13.2lf", celsiusWerte);
    printf("\n"); 
  } 
  // 



  return 0;
}
