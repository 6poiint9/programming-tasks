#include <stdio.h>
int weekday(int tag, int monat, int jahr) {
 // variablen 
 int wochentag, yv, y, c, result; 
  // für Jan und Feb
  if (monat == 1 || monat == 2) {
    //vorjahr
    yv = jahr - 1;
    y = yv % 100;
    c = yv / 100; 
  } 
  // restliche monate 
  else { 
    y = jahr % 100;
    c = jahr / 100;
   } 
   
  // Wochentag Formel 
  wochentag = (tag + (2.6 * monat - 0.2) + y + (y / 4) + (c / 4) - 2 * c);
  result = wochentag % 7;
  //int lol  = (tag += monat < 3 ? y-- : y - 2, 23*monat/9 + tag + 4 + y/4- y/100 + y/400)%7;  
 
 
 // gibt wochentag zurück
 return result; //(result + 5) % 7 + 1;;

}


int main() {
  printf("%d", weekday(29, 04, 2021));
  printf("%d\n", weekday(1, 1, 1999));
  return 0;
}
