#include <stdio.h>
// Notendurchschnitt berechnen
int main()
{
  // zähler 
  int count = 0; 
  // die zahlen zusammengerechnet 
  float summe = 0.0;
  // speichert die noten 
  float num;
  // max. 10 eingaben 
  while (count < 10) {
    // aüföhren wenn keine gültige eingabe
   if (scanf("%f", &num) != 1) {
      break; 
    }
   // nur zählen und summe rechnen mit gültigen eingaben 
   if (num <= 6.0 && num >= 1.0) {
      // die gültigen zahlen addieren 
      summe += num;
      count++;
    }
   else {
    break; 
   }
  }
  // scheuen ob gültige eingaben gemacht wurden
  if (count > 0) {
  // Berechnung 
  float durchschnitt = (float)summe / count; 
  // Ausgabe 
  printf("Durchschnitt (N=%d): %.2f", count, durchschnitt);
  }
  else {
   printf("Durchschnitt (N=0): 0.00\n");
  }
  return 0; 
}
