#include <stdio.h>
#define SPITZE 1
#define GUT 2
#define BEFRIEDIGEND 3
#define AUSREICHEND 4
#define DURCHGEFALLEN 5
#define JA 1
#define NEIN 0

int main() {
  // variablen für note und 
  unsigned int note, bestanden;
  // do-while loop falls integers außerhalb 1-5 eingegeben werden 
  do {
  printf("\nGeben Sie bitte eine Note (1-5) ein: ");
  scanf("%u", &note);
  // 1-4 bestanden 
  if (note == SPITZE)
    bestanden = JA;
  else if (note == GUT)
    bestanden = JA;
  else if (note == BEFRIEDIGEND)
    bestanden = JA;
  else if (note == AUSREICHEND)
    bestanden = JA;
  // nicht bestanden wenn 5 
  else if (note == DURCHGEFALLEN)
    bestanden = NEIN;
  // wenn nummer außer 1-5 eingegeben -> kein output 
  else 
      printf(" ");

  if (note >= 1 && note <= 5)
  bestanden ? printf("\nOK!") : printf("\nNICHT bestanden");
  }
  while (note > 6 || note <= 0);  

  return 0;
}
