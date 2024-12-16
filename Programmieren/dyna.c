#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// dynamic malloc allocation
int main()
{
  // variable size
  int n;
  // eingabe bitten
  scanf("%d", &n);
  // auf negative zahl prüfen
  if (n < 0 || n >= 100) {
    printf("eingabe muss größer 0 sein und kleiner gleich 100");
    return 1;
  }
  // int array-pointer
  int *arr;
  arr = (int*)malloc(n * sizeof(int));
   if (arr == NULL) {
    printf("alloc failed!!!");
    return 1;; 
  }
  
  // random nummern
  srand(time(NULL));
  // array füllen
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100; 
  }
  
  // ausgabe
  printf("Zahlen sind:\n");
  for (int i = 0; i < n; i++) {
    printf("%d, ", arr[i]); 
  }
  
  // freigeben
  free(arr); 
  arr = NULL; 

  return 0;
}
