#include <stdio.h>
// program for giving feedback based on the grade 
int main()
{
  // define uint variable for grade 
  unsigned int note;
  printf("Geben Sie bitte eine Note (1-5) ein: ");
  scanf("%u", &note);
  // Either failed or ok based on grade = 2 outcomes  
  switch (note)
  {
    case 1:
    case 2:
    case 3:
    case 4:
     printf("\nOK!");
     break;

    default:
     printf("\nNICHT bestanden");
  }
  return 0;
}







