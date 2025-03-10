#include <stdio.h>
#include <stdlib.h>

struct node {
  int data1;
  float data2;
  struct node *next;

}; 

int main() 
{

  // add at end
  struct node *end;
  end = (struct node*)malloc(sizeof(struct node)); 
   
  // initialized 
  struct node *head = NULL;
  struct node *one = NULL;  // Initialize to NULL
  struct node *two = NULL;
  struct node *three = NULL;
  struct node *four = NULL; 
  // Initialize as NULL 
  // assigning memory
  one = malloc(sizeof(struct node)); 
  if (one == NULL) {
       printf("Memory allocation failed\n");
       return 1; // Exit if allocation fails
    }
  // assigning data values
  one->data1 = 66;
  one->data2 = 67; 
  one->next = two; 
  



  return 0;
}
