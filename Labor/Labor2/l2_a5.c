#include <stdio.h>
// program that calculates concentration of alcohol in the blood
int main()
{
  // declatation of variables:
  /*(M) weight in kg, (V) volume ofbeverage in ml, 
     (e) alcohol content */
  int M, V, e;
  // gender-factor variables and reduction factor r  
  char g;
  float r;
  // const declaration of phi
  const float phi = 0.8;  
  // read stdin of user
  scanf("%c %d %d %d", &g,&M, &V, &e); 
  // convert weight in kg to g (it is actually *1000)  
  int Mg = M * 100;
  // gender-reduction factor 
  switch (g) 
  {
   case 'm': 
     r = 0.7; // male 
    break;
   case 'w':
     r = 0.60; // female 
    break;
   case 'k': // child 
     r = 0.80;
    break;
   default:
      printf("Error: invalid option\n");
      return 1; 
  } 
  // formula to calulate A 
  // A = V * e * phi
  float A = (float) V * e * phi; 
  // calculae concentration of alcohol in the blood
  // W = A / (m * r) 
  float W = A / (Mg * r); 

  // print out alcohol concentration
  printf("%.2f Promille\n", W);
  return 0;
}
