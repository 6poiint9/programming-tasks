#include <stdio.h>
//Funktion  die das Volumen und die Fläche einer Kugel berechnet
#define PI 3.1415
void sphere(int radius, double *pvolume, double *psurface) {
  // Volumen
  *pvolume = (4.0/3.0) * PI * (radius * radius * radius); 
  // Oberfläche 
  *psurface = 4.0 * PI * (radius * radius); 

}

// Ausgabe

int main()
{
 int radius = 5;
 double volume, surface;
 sphere(radius, &volume, &surface);
 printf("Radius: %d\nVolumen: %.1lf\nOberflaeche %.1lf\n", radius, volume, surface);
 return 0;
}


