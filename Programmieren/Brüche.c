/*
=> für zwei eingegebene Brüche das Produkt + Quotient berechnen
- Nutzer eingabe 
- 1. Bruch = Zähler 2. = Nenner 
- Funktion für rechnung 

=>Brüche mit struktur 
- 4 int variablen 

=sonst= 
- nicht testen ob durch 0
- brüche nicht kürzen 

*/
#include <stdio.h>

typedef struct node {
  // 1. Bruch 
  int a;
  int b;
  // 2. Bruch 
  int c;
  int d;

} node; 

// function für rechnung
void mal(node b);
void geteilt(node b); 

int main() 
{
  // what is this step => initialization is because not local? 
  node bruch;  
  //int a, b, c, d; 
  // einlesen 1. Bruch 
  scanf("%d/%d", &bruch.a, &bruch.b);  

  // einlesen 2. Bruch 
  scanf("\n%d/%d", &bruch.c, &bruch.d);
  
  // struct übergeben
  mal(bruch); 
  geteilt(bruch);   
  
  //printf("\n%d", multi);
  return 0;
}



void mal(node b) { 
  int res_zähler = b.a * b.c;
  int res_nenner = b.b * b.d; 
  printf("\n(%d.0/%d.0)*(%d.0/%d.0)=(%d.0/%d.0)", b.a, b.b, b.c, b.d, res_zähler, res_nenner);   
}

void geteilt(node b) {
 int res_zähler = b.a * b.d; 
 int res_nenner = b.b * b.c; 
 printf("\n(%d.0/%d.0)*(%d.0/%d.0)=(%d.0/%d.0)", b.a, b.b, b.c, b.d, res_zähler, res_nenner);   
}




