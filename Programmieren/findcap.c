/*
find FIRST capital letter of a string recursively

 */
#include <stdio.h>

char findcap(char *arr); 

int main()
{
 char arr[69]; 

 scanf("%68s", arr); 

 char result = findcap(arr); 
 
 printf("%c", result); 

 return 0; 
}


char findcap(char *arr) {
  
  if (*arr >= 'A' && *arr <= 'Z') {
   return *arr; 
  }
  return findcap(arr + 1); 
 }








