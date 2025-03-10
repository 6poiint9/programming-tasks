/*
string auf den erster pointer zeigt auf 2. kopieren
*/
#include <stdio.h>

// funktion prototypen
char ownstrcpy(char *str1, char *str2); 

int main() 
{
  char og_string[] = "Programming"; 
  
  char copystring[40]; 

  // pass by reference
  ownstrcpy(og_string, copystring); 

  printf("%s", copystring); 
  
  return 0; 

}

char ownstrcpy(char *str1, char *str2) {
 // go through the whole string 
  while (*str1 != '\0') {
    // character von str1 werden zu str2 transportiert
    *str2 = *str1; 
    str1++;
    str2++; 

  }
  *str2 = '\0'; 
    
 return *str2; 
} 















