#include <stdio.h>
//#include <string.h>

int main()
{
  // variablen festlegen
  float eingabe, eur, usd;
  const float usdEur = 0.9468;
  const float eurUsd = 1.0532;
  int währung;
  // fragen ob $ oder Euro umrechnen 
  printf("bitte betrag eingeben und umrechnungsWährung bestimmen [EUR = 1,  USD = 2]\n"); 
  // stdin verarbeiten
  scanf("%f %d", &eingabe, &währung);  
  // umrechnung des betrags 
  if (währung == 1)
  {
    float usd = eingabe * eurUsd; 
    printf("%.2f Euro ist = %.2f$\n", eingabe, usd);
  }
  else if (währung == 2)
  {
    float eur = eingabe * usdEur;
    printf("%.2f Dollar ist = %.2f Eur\n", eingabe, eur);
  }
  else 
  {
    printf("Error: Währungseingabe ist ungültig!");
  }


  return 0;
}
