#include <stdio.h>
// in einer eingegebenen Zeichenkette jeden Vokal mit einem zusätzlich eingegebenen Buchstaben ersetzen
int main()
{
  // varable für einzelnen char
  char vowel;
  // string 
  char str[40];
  // einlesen
  scanf(" %c %39s", &vowel, str);
  // geht durch jeden character  
  for (int i = 0; str[i] != '\0'; i++) {
   // Kontrollieren ob Vokal
   if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
      str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      // Vokale mit character ersetzen 
      str[i] = vowel; 
   }
  }
  printf("%s", str);
  return 0;
}
