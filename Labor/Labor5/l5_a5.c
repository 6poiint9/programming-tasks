#include <stdio.h>
// in einer eingegebenen Zeichenkette jeden Großbuchstaben mit dem entsprechenden Kleinbuchstaben und umgekehrt ersetzen 

int main()
{
  // string array
  char str[41];
  // einlesen 
  scanf("%40s", str); 
  // durch alle char durchgehen 
  for (int i = 0; str[i] != '\0'; i++) {
   // auf Kleinbuchstaben prüfen 
   if (str[i] >= 'a' && str[i] <= 'z') {
      // Kleinbuchstaben in groß umwandel indem -32 
      str[i] = str[i] - ('a' - 'A');
    }
   // auf Großbuchstaben prüfen  
   else if (str[i] >= 'A' && str[i] <= 'Z')  {
       // Groß zu klein indem man +32 macht 
      str[i] = str[i] + ('a' - 'A');
     }
  }
  // ausgabe
  printf("%s", str);

  return 0;
}


