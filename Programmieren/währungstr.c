#include <stdio.h>
#include <string.h>

int main()
{
  // variablen festlegen
  float eingabe, eur, usd;
  const float usdEur = 0.9468;
  const float eurUsd = 1.0532;
  char währung[5];
  // fragen ob $ oder Euro umrechnen 
  printf("bitte betrag eingeben und umrechnungsWährung bestimmen [EUR oder USD]\n"); 
  // stdin verarbeiten
  scanf("%f %s", &eingabe, währung);  
  // umrechnung des betrags 
  if (strcmp(währung, "EUR") == 0) 
  {
    float usd = eingabe * eurUsd; 
    printf("%.2f€ ist = %.2f Dollar$\n", eingabe, usd);
  }
  else if (strcmp(währung, "USD") == 0) 
  {
    float eur = eingabe * usdEur;
    printf("%.2f$ Dollar ist = %.2f€\n", eingabe, eur);
  }
  else 
  {
    printf("Error: Währungseingabe ist ungültig!");
  }


  return 0;
}
