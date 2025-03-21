#include <stdio.h>

int main()
{
 int i;
 int *ptr;
 int **ptrptr; 
 ptr = &i;
 ptrptr = &ptr; 
 i = 1;
 printf("%d\n", i);
 printf("%d\n", *ptr);
 **ptrptr = 2;
 printf("%d\n", i); 

  return 0;
}

/*

    Definition einer Variablen i vom Typ int
    Definition eines Pointers ptr auf den Typ int
    Definition eines Pointers ptrptr auf einen int-Pointer
    Zuweisung der Adresse von i an den Pointer ptr
    Zuweisung der Adresse von ptr an den Pointer ptrptr
    Zuweisung des Wertes 1 an die Variable i
    Ausgabe des Werts von i
    Ausgabe des Werts des Objekts, auf das der Pointer ptr zeigt, mithilfe des Dereferenzierungsoperators
    Zuweisung des Werts 2 auf i, aber über den Dopplerpointer ptrptr (NICHT direkt!)
    Ausgabe des Wertes von i

*/
