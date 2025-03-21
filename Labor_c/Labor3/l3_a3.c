#include <stdio.h>

int main()
{
  // declare in variables
  int num1, num2;
  // read stdin 
  scanf("%d %d", &num1, &num2);
  // loop
  for (int e = 0; e < num1; e++)
  {
    for (int i = 0; i < num2; i++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}
