#include <stdio.h>
// Zeichenkette per Pass-by-Referenz in Großbuchstaben umwandeln

// pointer als parameter
char  toUpper(char *str) {
  // schleife bis null terminator
  for (int i = 0; str[i] != '\0'; i++) {
    // schauen ob zwischen klein a - z 
    if (str[i] >= 'a' && str[i] <= 'z') {
        // um -32 ASCII werte subtrahieren  
        str[i] = str[i] - 32;
    }
  }
  // Rückgabe
  return *str;
}



// Ausgabe
/*
int main ()
{
char arr[] = "Hallo Welt";
toUpper(arr);
printf("%s\n", arr);
return 0;
}
*/
