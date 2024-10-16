#include <stdio.h>

int main()
{
  int eingabe;
  printf("zahl geingeben! \n");
  scanf("%d", &eingabe);

  if (eingabe % 2 == 0) 
  {
    printf("wert is gerade\n");
    if (eingabe > 69)
    printf("Und zahl ist größer 69\n");
  }
  else
  {
   printf("zahl ist ungerade");
  }

  return 0;
}

