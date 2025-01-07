#include <stdio.h>
#include <math.h>
//  Potenz (a+b)^n soll für positive (int) n ITERATIV berechnet werden
int potenz(int a, int b, int n); 

int main()
{
 int a, b, n;
 // read user input
 scanf("%d %d %d", &a, &b, &n); 
 //pass by value a b und c 
 int result = potenz(a, b, n);
 // print out the result 
 printf("%d", result); 

  return 0;
}

int potenz(int a, int b, int n) {
 int c = a + b; 
 //int res = 0; 
 //for (int i = 0; i < n; i++) {
    //int res = c * c ;
    int pot = pow(c, n);  
  //}
 return pot; 
}



