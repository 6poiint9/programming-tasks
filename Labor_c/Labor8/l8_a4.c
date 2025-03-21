#include <stdio.h>
// recursive Funktion für  y=(a + 2 * n * x)

float Formel(float a, float x, int N);

int main()
{
  // variablen
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
  // y mit 0 initialisieren 
  float y = 0;
  // mit int 1 anfangen weil (mal)
 for (int i = 1; i <= N; i++) {
    // anfangswert 2 mit i nach jeder iteration vergrößern
    y += (a + 2.0 * i * x);  
  } 
 return y;
}


