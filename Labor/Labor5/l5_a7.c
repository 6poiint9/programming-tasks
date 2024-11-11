#include <stdio.h>
//  eine eingegebene Zeichenkette Umkehren 
int main()
{
  // array
  char str[41];
  // zähler bei 0 anfangen 
  int lenght = 0;  
  //einlesen 
  scanf("%s", str);
  // zählen 
  for (int z = 0; str[z] != '\0'; z++) {
    lenght++; 
  }
  // ausgabe ist rückwärts anfangen, -1 fur null term. 
  for (int i = lenght - 1; i >= 0; i--) {
   printf("%c", str[i]);  
  }
  
  return 0;
}

