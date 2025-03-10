/*
Minimum einer Ganzzahlenfolge berechnet und zurückgibt

parameter = Pointer auf ein Array und die Länge des Arrays

*/
#include <stdio.h>

int minimum(int *arr, int size); 

int main()
{
  int size = 4;

  int numbers[] = {4, 6, 9, 5}; 
  
  // pass by referenz + value
  minimum(numbers, size); 
  
  // Ausgabe
  printf("%d", minimum(numbers, size)); 
 return 0; 
}

int minimum(int *arr, int size) {
  // vergleich mit erster zahl starten
  int min = arr[0]; 
  for (int i = 1; i < size; i++) {
    if (arr[0] > arr[i]) {
      min = arr[i]; 
    }
  }
  return min; 
}










