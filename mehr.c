#include <stdio.h>

//programm für berechnung von mehrwertsteuer

int main()
{
  //variablen für Eingabe und output
  float betrag, gesamt;
  const float MWST = 1.19; 
  //nutzer für betrag eingabe bitten 
  printf("Bitte geben Sie nen Betrag ein: ");
  //nutzer eingabe 
  scanf("%f", &betrag);
  //berechnung 
  gesamt = betrag * MWST; 
  //ergebnis darstellen
  printf("Das von %f ergebniss ist: %f", betrag, gesamt);
 
  return 0; 
}
