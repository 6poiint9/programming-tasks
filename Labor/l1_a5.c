/* the preprocessor directive #define... is used in vscode
  so that no warnings are generated when using potentially unsecure funcions like scanf()
  I commented it out since I use Neovim btw.*/
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// A program that reads 3 integers and pastes them out formatted in reverse order 
int main() 
{
    // declaration of variables 
    int num1, num2, num3;        
    // reading user input 
    scanf("%d %d %d", &num1, &num2, &num3);
    // prints out the numbers formatted and in reverse order
    printf("Zahl 3: %4d\n", num3);
    printf("Zahl 2: %4d\n", num2);
    printf("Zahl 1: %4d\n", num1);
    return 0;
}

