#include <stdio.h>

int main ()
{
  float fahr, celsius;
  // Nutzer um eingabe bitten
  printf("temperatur eingeben!!!\n");
  // lesen der Temperatur von stdin 
  scanf("%f", &fahr);
  //umrechnug in celsius => 5 oder 9 muss in float angegeben werden 
  celsius = (5 / 9.0) * (fahr - 32);

  printf("the temperatur in celsius ist: %.3f \n", celsius); 

  return 0;
}


