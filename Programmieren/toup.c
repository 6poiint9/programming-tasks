/*
in großbuchstaben umwandeln  

*/
#include <stdio.h>

char toUpper(char *arr); 

int main()
{
  char arr[] = "Ersin Döner"; 

  toUpper(arr); 

  printf("%s",arr); 
  
  return 0;
}

char toUpper(char *arr) {
 for (int i = 0; arr[i] != '\0'; i++){
   if (arr[i] >= 'a' && arr[i] <= 'z') {
      arr[i] = arr[i] -32; 
    }
  }
  return *arr; 
}





