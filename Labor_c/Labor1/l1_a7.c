#include <stdio.h>
// program that reads 2 integers and outputs them in Hexadecimal 
int main()
{
  // declaration of variables
  int num1, num2; 
  // read stdin  
  scanf("%d %d", &num1, &num2); 
  //print out numbers in Hexadecimal
  printf("1. Zahl: 0x%x\n", num1); 
  printf("2. Zahl: 0x%X\n", num2); 
  return 0;
}








