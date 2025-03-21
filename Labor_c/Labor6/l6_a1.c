#include <stdio.h>

//Minimum einer Ganzzahlenfolge berechnet und zurückgibt

// parameter pointer und int für länge 
int minimum(int *arr, int länge) {
  // mit ersten element anfange um zu vergleichen 
  int klein = arr[0]; 
  // schleife um größe zu vergleichen ab 2. element 
  for (int i = 1; i < länge; i++) {
    if (arr[i] < klein) {
      // vaiable dem neuen kleinsten element zuordnen
      klein = arr[i]; 
      // pointer auf die kleinste stelle 
      arr = &klein; 
    }
   }
 // pointer zurückgeben für kleinste zahl 
 return *arr;
} 






    
// Ausgabe
/*
int main()
{
  int numbers[] = {4, 6, 9, 5};
  printf("%d", minimum(numbers, 4));
  return 0;
}
*/


