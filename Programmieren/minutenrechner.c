#include <stdio.h>

int main ()
{
  int sekunden, ergebinssec, ergebinsmin; 
  // Eingabe sekunden vom Nutzer
  printf("bitte geben Sie die Sekunden ein \n");
  scanf("%d", &sekunden);
  // Berechnung der sekinden zu minuten
  ergebinsmin = sekunden / 60; 
  // Berechnung der Rest-Sekunden
  ergebinssec = sekunden % 60;  
  // Ausgabe 
  printf("%d Sekunden sind %d minuten \n und %d Restsekunden", sekunden, ergebinsmin, ergebinssec); 

  return 0;
  

}



