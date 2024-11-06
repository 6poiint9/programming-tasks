#include <stdio.h>
#include <stdbool.h> // true false für schaltjahr 

// Funktionstypen 
void printCalenderbody(); 
bool leapyear(int year); // true or false 
int startdayofmonth(int month, int year);
void printmonth(int month);
void printcal(int month, int year); 
void printcalheader(int month, int year);
void printcalbody(int month, int year);

int main()
{
  int month, year; 
  printcalheader(month, year) {  
  printf("Jahr eingeben: ");
  scanf("%d", &year);
  printf("Monat eingeben: ");
  scanf("%d", &month); 
  }
  // Calender Tabelle
  // falls ungültige monatseingebe
  do {
   printf("Monat eingeben: ");
   scanf("%d", &month); 
  }
  while (month < 1 || month > 12); 
  

  // Name des monats ausgeben
  switch(month) {
    case 1:
     printf("Januar");
     break; 
    case 2:
     printf("Februar");
     break; 
    case 3:
     printf("März");
     break; 
    case 4:
     printf("April");
     break;
    case 5:
     printf("Mai");
     break;
    case 6:
     printf("Juni");
     break;
    case 7:
     printf("July");
     break;
    case 8:
     printf("Aug");
     break;
    case 9:
     printf("Sep");
     break;
    case 10:
     printf("Okt");
     break;
    case 11:
     printf("Nov");
     break;
    case 12:
     printf("Dec");
     break;
    default:
     printf("ungültige eingabe");
     break;  
  }

  return 0;
}


























