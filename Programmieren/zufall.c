#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// eine random zahl von 0-99 wird ausgewählt und benutzer ratet bis richtig
int main() {
  
  // jedes mal wenn programm rennt neue random zahl generieren 
  srand(time(NULL)); 
  // variablen
  int min = 0, max = 99;
  int raten; 
  // random nummer von 0-99 
  int randomNum = min + rand() % (max - min + 1);
  // do while semester 
  do {
   printf("geben sir eine zahl ein 0-99:\n");
   scanf("%d", &raten); 
  //printf("%d\n", randomNum);
   if (raten == randomNum) {
     printf("Richtig!!!");
    }
   else if (randomNum > raten) {
       printf("Zahl muss größer sein\n");
      // scanf("%d", &raten); 
     }
   else {
        printf("Zahl muss kleiner sein\n");
        //scanf("%d", &raten); 
      }
    
   }
   while (raten != randomNum); 
  return 0;
}

 


