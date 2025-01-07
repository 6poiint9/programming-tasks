#include <stdio.h>
//  ersten Großbuchstaben in einem eingegebenen String rekursiv findet und ausgibt
char getcap(char* str); 

int main()
{
  // char array für string
  char arr[33];
  scanf("%s", arr);
  // pass by reference 
  char res = getcap(arr); 
  printf("%c",res); 

  return 0;
}


char getcap(char* str) {
  // ende von string kennzeichnen
   if (*str == '\0') {  
        return ' ';
    }
  // falls gr0ßbuchstabe gefunden -> return 
    if (*str >= 'A' && *str <= 'Z') {  
        return *str;
    }
   // buchstaben nacheinander untersuchen 
    return getcap(str + 1);  
}
  
