#include <stdio.h>
/* Lesen Sie eine Zeichenkette ein und geben Sie einen Teil davon aus.
durch zwei Indizes (von/bis) definiert
*/

int main()
{
  char str[41];
  // variaben 
  int von, bis; 
  scanf("%40s %d %d", str, &von, &bis);
  // titel 
  printf("%s %d-%d: ", str, von, bis);
  // schlEife bei (von) sartet und bis <=(bis) geht 
  for (int i = von; i <= bis && str[i] != '\0'; i++) {
    // die gekürtzten character ausgeben
    printf("%c", str[i]);
  }
  return 0;
}

