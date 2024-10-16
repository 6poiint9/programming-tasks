#include <stdio.h>

// going to try out a number of format specifiers/placeholders 
int main()
{
    printf("String: %s \n", "Das ist eine Zeichenkette");
    // %d is used for integers 
    printf("Ganze Zahl: %i \n", 42);
    // %f is used for floating pint numbers 
    printf("Fliesskommazahl: %f \n", 3.1415);
    /* The number should be printed out as 00003.14 -> padding applied*/
    printf("Fliesskommazahl mit Formatangabe: %08.2f \n", 3.1415);
    return 0;
}
