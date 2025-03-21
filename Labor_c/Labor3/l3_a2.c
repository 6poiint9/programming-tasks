#include <stdio.h>

int main()
{
  // declare variables int and char = *
  int num;
  // read stdin from user
  scanf("%d", &num);
  // for loop
  for (int i = 0; i < num; i++)
  {
    if (i % 2 == 0)
    {
     printf("*"); 
    }  
    else
    {
      printf("_");
    }
  }
  return 0;
} 
