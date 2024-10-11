#include <stdio.h>

int main()
{
  // declaration of variables  
  int ganz;
  float gleit;
  char ch;
  // Read user input 
  scanf("%d %f %c", &ganz, &gleit, &ch);
  // print out the formatted
  printf("%-14s: %010d\n", "Ganzzahlen", ganz);
  printf("%-14s: %.5f\n", "Gleitkommazahl", gleit);
  printf("%-14s: %c\n", "Zeichen", ch); 
 

  return 0;
}



