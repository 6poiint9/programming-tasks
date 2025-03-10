/*
- Kunden-managememt-system

=> struct für Kundendaten
member:
- Kundennummer -> int id
- Vorname -> char vor[]
- nachname -> char nach[]

=> 2 Kunden 
- Kunde 1 = 1, Name: Hans Maurer.
- Kunde 2 = scanf 

=> Output 
- beide Kunden
- = id: vorname nachname 

*/

#include <stdio.h>
#include <string.h>

typedef struct kunden {
  // struct member 
  int id;
  // Vor- und nachname 
  char vor[33];
  char nach[33]; 
}kunden;
// get input and change parameters 
void get_input(kunden *ptr); 
//void create_kunde(kunden daten);

int main()
{
  // für kunde 2
  kunden *ptr1, daten1;
  ptr1 = &daten1;

  ptr1->id = 1;
  strcpy(ptr1->vor, "Hans");
  strcpy(ptr1->nach, "FEEEIN");
  // für kunde 2
  kunden *ptr2, daten2;
  ptr2 = &daten2;
  // scan stuff
  get_input(ptr2); 
  // 1. Kunde  
  printf("\n%d: %s %s", ptr1->id, ptr1->vor, ptr1->nach);
  // 2. Kunde 
  printf("\n%d: %s %s", ptr2->id, ptr2->vor, ptr2->nach); 
  return 0;
}

void get_input(kunden *ptr) {
 scanf("%d %32s %32s", &ptr->id, ptr->vor, ptr->nach);
}




















