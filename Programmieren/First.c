#include <stdio.h>

// void function with parameter 
void first(char name[]) {
  //int age;
  //char name[33];
  //printf("enter name:\n");
  //scanf("%32s", name); 
  printf("hallo %s\n", name);
}

int myn(int x, int y) {
  return x + y;
}

int main() 
{
  first("adama");
  printf("the restult is = %d",myn(10, 59));
  //printf("enter name:\n");
  //scanf("%s", name); 
  printf("Moiin :) \n");
  return 0;  
}



