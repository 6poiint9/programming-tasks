#include <stdio.h>

typedef int reel;

 typedef struct {
  reel number;
  char meal[22]; 
  reel weight;
  float age; 

}p1, p2, test;

void ok(test s); 

int main() {
   
  p1 *ptr, p11; 
  p2 *ptr2, p22; 
  ptr = &p11;
  ptr2 = &p22; 
  
 test test1;
 test1.number = 383;
 test1.weight = 909;
 
 ok(test1); 

  printf("\nhow much do you weight?");
  scanf("%d",&ptr->weight);
  ptr->age = 6.9; 
  
  p2 ok = {69, "chicken", 145, 23}; 


  printf("%d", ptr->weight);
  printf("%.1f\n",ptr->age); 
  return 0;
}


void ok(test s) {
  s.number = 69; 
 

}

