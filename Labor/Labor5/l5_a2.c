#include <stdio.h>

int main()
{
  // char-array variable declarieren
  char string[40];
  // Buchstabenzähler 
  int count = 0; 
  // einlesen 
  scanf("%39s", string);
  for (int i = 0; string[i] != '\0'; i++) { // bei null terminator wird beendet    
    // mithilfe ASCII auf kleinbuchstabe untersuchen
    if (string[i] >= 'a' && string[i] <= 'z') {
     // zählen 
     count++;  
    }
  }
  printf("%d Kleinbuchstaben", count); 
  return 0;
}
