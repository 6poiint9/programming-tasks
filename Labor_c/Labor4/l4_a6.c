#include <stdio.h>

// eine funtion  Zeichenkette als Parameter übernimmt und die Länge der Zeichenkette zurückgibt
// char-zähler 

// string-array "test" als parameter 
int stringlength(char test[]) {
  // char-Zähler ab 0 starten   
  int zähler = 0;
    // zählen bis the \0 "null character" erreicht ist   
    while (test[zähler] != '\0') {
        zähler++;
    }
    // char-zahl zurückgeben
    return zähler; 
}
 
/*
int main () {
  printf("%s hat %d Zeichen", "hallo", stringlength("hallo"));
  return 0; 
}
*/

