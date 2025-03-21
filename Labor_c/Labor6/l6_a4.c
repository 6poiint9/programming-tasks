#include <stdio.h>
// eine Zeichenkette an eine 2. Zeichenkette/char-array anhängt

void append(char *ziel, const char *von) {
  // zum ende des ersten strings gelangen  
  while (*ziel != '\0') {
   ziel++;
  }
  // string rüber kopieren 
  while (*von != '\0') {
    *ziel = *von;
    ziel++;
    von++;
  }
  // bei null terminator aufhöhren
  *ziel = '\0';
  
}




// Ausgabe
/*
int main() 
{
 char buffer[40] = "Hallo ";
 append(buffer, "Welt");
 printf("%s\n", buffer);
 return 0;
}
*/

