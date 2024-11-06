// added another file into the program 
#include "addfunc.c" 
#include <stdio.h>
// Temperature convertion table 

int main()     {
int fahr;
printf(" Temp Converter \n");
printf("%d", add(60, 9));
int goal = 0; 
for (fahr = 300; fahr == goal; fahr = fahr - 20)
  printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));     
  }



