#include <stdio.h>
#include <assert.h>
int main() 
{
  int moin = 9;
  int *pmoin = &moin;  
  int lol;
  int **pmoin2 = &pmoin; 
  lol = *pmoin;
  printf("%d", **pmoin2); 
  //assert(lol == 10);
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("%d\n", lol);
  // addresse von moin
  printf("%p\n", (void*)&moin); 
  // mit pointer 
  printf("%p\n", (void*)pmoin);

  // WERT auf den pointer zeigt
  printf("%d\n", *pmoin);
  // = WERT von moint
  printf("%d\n", moin); 
  
  // addresse vom pointer
  printf("%p\n", (void*)&pmoin);

  // decrement
  pmoin--; 
  printf(" %p\n", (void*)pmoin);
    printf("%d\n", *pmoin);
  return 0;
}
