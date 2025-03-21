#include <stdio.h>
// zählen Sie alle Vokale 
int main() 
{
  // string array
  char string[40];
  // zähler 
  int count = 0;
  // eingabe 
  scanf("%39s", string);
  // von ersten bis letzen buchstaben achten
  for (int i = 0; string[i] != '\0'; i++) {
    // klein und groß-geschriebene achten 
    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
        string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
      // zählen
      count++;
    }
  }
  printf("%d Vokale", count); 
  return 0;
}
