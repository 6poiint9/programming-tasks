#include <stdio.h>

int main() 
{
  int arra[5] = {1, 2, 3, 4, 5}; 
  printf("%p\n", arra); 
  printf("%d\n", *arra + 1);
  
  for (int i = 0; i < 5; i++ ) {
    printf("%d", *arra + i); 

  }
    
  return 0;
}
