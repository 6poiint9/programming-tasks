#include <stdio.h>
// 2 pointer als parameter -> kopiert den string auf den ein pointer zeigt zum anderen  

// von ist const weil -> standart + sichergehen 
void ownStrcpy(char *ziel, const char *von) {
  // sichergehen das alles copiert wird
   while (*von != '\0') {
    // string copieren/gleichsetzen
    *ziel = *von; 
    // durch die buchstaben gehen
    von++;
    ziel++; 
  }  
   // bei null terminator stoppen 
   *ziel = '\0';
}


// Ausgabe

int main() 
{
char originalString[] = "Programmieren";
char copiedString[40];
ownStrcpy(copiedString, originalString);
printf("%s", copiedString);
return 0;
}

