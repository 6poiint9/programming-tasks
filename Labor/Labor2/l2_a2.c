#include <stdio.h>

int main() 
{
  // declare variables
  float celsius, fahr; 
  scanf("%f", &fahr);
  // conversion of fahrenheit to celsius
  celsius = 5 * (fahr - 32)/9; 
  printf("%.1f Grad Fahrenheit = %.1f Grad Celsius\n",fahr, celsius);

  return 0;
}
