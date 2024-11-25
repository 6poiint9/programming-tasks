#include <stdio.h>
// pointer auf einen char array der den string wieder ausliesßt 
int main() 
{
  // array mit 40 zeichen 
  char arr[40];
  // nutzer eingabe => arr ist pointer auf erstes element 
  scanf("%39s", arr);
  // ausgabe 
  printf("%s", arr);
  return 0;
}


