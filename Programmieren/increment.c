#include <stdio.h>
// get math functions
#include <math.h>
// print increments without for loop frotm 1 to 10 

// function declaration 
void myfunc(int x); 
// math 
void math();

int main()
{
  myfunc(0);
  math();
  return 0;
}


// function definition
void myfunc(int x) {
 while (x < 10) { 
 printf ("%d\n", ++x);
  }
 //return printf("these are mynumbers %d", myfunc(5));
}

void math() {
  printf("%.2lf\n", sqrt(16));
  printf("%.2lf\n", pow(2, 3)); 
  printf("%f", ceil(1.6));
  printf("%f", floor(3.6));

}






