/*
Volumen + Fläche von Kugel berechnen

*/

#define PI 3.1415

#include <stdio.h>

void sphere(int radius, double *volumen, double *surface);

int main()
{
 int radius = 5; 
 double volumen, surface; 
 
  scanf("%lf %lf", &volumen, &surface); 
 // pass by reference
 sphere(radius, &volumen, &surface);

 return 0; 
}

void sphere(int radius, double *volumen, double *surface) {

  // Kreisfläche A = PI * r²

  // Fläche 4 * PI * r²
  *surface =(double)4.0 * PI * (radius*radius); 

  // Volumen 4/3*PI * r³
  *volumen =(double) 4.0/3.0 * PI * (radius*radius*radius); 
}
