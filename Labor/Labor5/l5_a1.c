#include <stdio.h>

int main()
{
  // variablen
  double viernum[4]; 
  // 4 double einlesen
  for (int a = 0; a < 4; a++) {
   scanf("%lf", &viernum[a]);
  }
  // variable für kleinste Zahl und Index
  double min = viernum[0];
  int index = 0; 
  // schleife um kleinste zahl und index zu finden 
  for (int i = 0; i < 4; i++) {
    // array-zahlenfolge mit zahlen vergleichen
    if (viernum[i] < min) {
      min = viernum[i];
      index = i; 
    }
  }
  printf("Kleinste Zahl: %.1lf an Index %d ", min, index); 
  
  return 0;
}
