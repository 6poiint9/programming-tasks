#include <stdio.h>

int main()
{
  int value = 42;
  // pointer auf die addresse von value
  int *pvalue = &value;
  // ausgabe mit dereference operator "*"
  printf("%d\n", *pvalue); 
  value = 85;
  printf("%d\n", *pvalue);
  value++; 
  printf("%d\n", *pvalue);
  return 0;
}
