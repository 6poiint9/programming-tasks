#include <stdio.h>
// kleine 1 x 1 Tabelle
int main(int argc, char *argv[])
{
  //int gesamt = 10; 
  //int ersteS[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // spalten höhe
  //for (int b = 1; b <= 10; b++) {
   //printf("_\t");
   //printf("%d\t",b); 
   //printf("_\t");
  //}

  for (int h = 1; h <= 10; h++) {
     
     for (int s = 1; s <= 10; s++) {
      printf("%d\t", s * h);
    }     
    //printf("%d\t", h);
    printf("\n");

  }
  


  return 0;
}
