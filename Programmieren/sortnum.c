/*
Int Sortierer

=> erste nummer n gibt an wie viel noch eingelesen wird
- wird nicht mit sortiert 

=> integers werden dynamisch gespeichert
- mit malloc 

*/

#include <stdio.h>
#include <stdlib.h>

void sortnumbers(int n, int *arr);

int main()
{
  // dynamisches array initialisieren
  int *arr = NULL; 
  // variable n festlegen
  int n;
  // n einlesen 
  scanf("%d", &n); 
  // array größe festlegen und speicher zuweisen 
  arr =(int*)malloc(n*sizeof(int));
  // speicher kontrolle
  if (arr == NULL) {
    printf("malloc failed");
    return 1; 
  } 
  // zahlen einlesen 
  for (int i = 0; i < n; i++) {
     scanf(" %d", &arr[i]); 
  }
  // array und n der funktion übergeben
  sortnumbers(n, arr); 
  // ausgabe
 
  // speicher freigeben
  free (arr); 
  // pointer auf NULL zeigen lassen um dangling pointer zu vermeiden 
  arr = NULL; 
  return 0;
}

void sortnumbers(int n, int *arr) {
/* Find biggest number 
  // vergleich starten mit erster zahl 
  int small = arr[0];
  // schleife zu sortieren (größte zahl), bei 1 anfangen weil mit 0 vergleich 
  for (int i = 1; i < n; i++) {
    if (small < arr[i]) {
      small = arr[i]; 
   }
  }
  printf("%d", small); 
}
*/  
// Bubble sort 
 // aüßere um zu traversieren n-1 mal 
 for (int i = 0; i < n -1; i++) {
    // innere um zu vergleichen 
    for (int j = 0; j < n - 1 - i; j++) {
     // if statement falls größer 
     if (arr[j] > arr[j+1]) {
       // aktuelles element in temp variable speichern
       int temp = arr[j]; 
       // nächstes element zu aktueller positions platzieren
       arr[j] = arr[j+1]; 
       // aktuelles element in nächste position platzieren
       arr[j + 1] = temp; 
      } 

    } 
  }
  // ausgabe 
  for (int i = 0; i < n; i++) {
   printf(" %d", arr[i]);  
  }
}




















