#include <stdio.h>
// ITERATIVE Funktion für  y=(a + 2 * n * x)

float Formel(float a, float x, int N);

int main()
{
  float a, x;
  int N;
  // einlesen
  scanf("%f %f %d", &a, &x, &N);
  // pass by value
  float res = Formel(a, x, N);
  // ausgabe
  printf("%.1f", res);
  return 0;
}

float Formel(float a, float x, int N) {
 // wenn N = 0 => 0 widerhohlungen
 if (N == 0) {
    return 0; 
  }
 // die vorherigen reihen werden mit der aktuellen addiert 
 else {
    return (a + 2 * N * x) + Formel(a, x, N - 1);    
  }

}


