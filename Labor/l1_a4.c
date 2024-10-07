#include <stdio.h>

// going to try out a number of format specifiers/placeholders 
int main()
{
    // %s is a placeholder for a string data-type 
    // the text can be printed out the following ways
    //printf("String:Das ist eine Zeichenkette \n");
    printf("String: %s \n", "Das ist eine Zeichenkette");
    // %d is used for integers 
    printf("Ganze Zahl: %i \n", 42);
    // %f is used for floating pint numbers 
    printf("Fliesskommazahl: %f \n", 3.1415);
    /* The number should be printed out as 00003.14
    to achieve this we can apply some "padding" => %08.2f
    the 0 = padding type, the 8 = total numbers, 2f = digits after comma and float*/
    printf("Fliesskommazahl mit Formatangabe: %08.2f \n", 3.1415);
    return 0;
}
