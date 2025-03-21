#include <stdio.h>

int main()

{
  int ganz1, ganz2, ganz3;
  // double instead of float => better precision 
  double flies;
  char zeichenk[69];
  
  // read stdin of 3 integers 
  scanf("%d %d %d", &ganz1, &ganz2, &ganz3 );
  printf("Ganze Zahlen: %d, %d, %d\n", ganz1, ganz2, ganz3);
  //read sdin of floating point number 
  scanf("%lf", &flies);
  printf("Fliesskommazahl mit Formatangabe: %.2f\n", flies); 
  // read stdin of a string
  scanf("%68s", zeichenk);
  printf("Zeichenkette: %s\n", zeichenk); 
  return 0;
}
