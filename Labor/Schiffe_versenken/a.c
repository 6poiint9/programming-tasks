#include <stdio.h>
// Schiffe Versenken!

//Brett position der Shiffe => 10x10 Feld 1-10, A-J
// 
//const int Länge = 10;
//const int Breite = 10;

void Brett() {
  // buchstaben reihe
  char abc_line[1][11] = { { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'} };
  for (int i = 0; i < 1; i++) {
   for (int j = 0; j < 11; j++)
  
  printf("%c", abc_line[i][j]); 
  }
  // nummer reihe 
  printf("\n");
  for (int i = 1; i < 10; i++) {  
    printf("%2d\n", i);  
  }
  /*
  char point_line[10][10] = { { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',}};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
     printf(" %c", point_line[i][j]);
  }
  */ 
    for (int j = 0; j < 10; j++) {
            printf("."); // Print the dots
        }
        printf("\n"); // Move to the next row


}
int main()
{
  Brett();
  return 0;
}

