#include <stdio.h>
// Eine temperaturtabelle in Celsius zu Fahrenheit, ohne user input
// 20-er schritte vom -20 bis 300 

int main() {
  // Temperatur Einheit
  printf("Celsius Fahrenheit\n"); 
  // array für die celsius werte
  int celsiusWerte[] = {-20, 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
  // Umrechnung in schleife
  for (int cf = 0; cf < 17; cf++) {
    printf("%7d", celsiusWerte[cf]);
    // umrechnung 
    int fahrenheitWerte = celsiusWerte[cf] * 9 / 5 + 32;
    // warum %11 
    printf("%11d", fahrenheitWerte);
    printf("\n"); 
  } 
  return 0;
}










