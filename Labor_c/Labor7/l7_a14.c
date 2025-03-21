#include <stdio.h>
// feld index [2] mit 42 ersetzen
int main()
{
  // array der länge 4 
  int arr[4];
  // einlesen
  for (int i = 0; i < 4; i++) {
    scanf("%4d",&arr[i]); 
  }
  // unveränderte ausgabe
  for (int b = 0; b < 4; b++) {
   printf("%d ", arr[b]);
  }
  // index [2] mit 42 ersetzen
  arr[2] = 42;
  // neue zeile
  printf("\n");
  // veränderte ausgabe 
  for (int b = 0; b < 4; b++) {
   printf("%d ", arr[b]);
  }

    

  return 0;
}
