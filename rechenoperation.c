#include <stdio.h>

int main() 
{
  int nummer;
  float decimal;
  printf("gib nen nummer ein \n");
  scanf ("%d" , &nummer);
  printf("gib ne dezimalzahl ein\n");
  scanf("%f", &decimal);  
  printf("Die normale zahl ist %d \ndie dezimalzahl ist %f \n", nummer, decimal);

  return 0;
}
