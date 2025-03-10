// Linked list mit min. 3 nodes
// Node prototype => data und pointer zum nächsten node 
// Funktionen zu verwenden: 
// create_node()  = erzeugt neuen node + returns den pointer
// insert_at_beginning() = fügt einen node am anfang hinzu
// display() = printf werte aller nodes
// free_list() = free den speicher der nodes 

#include <stdio.h>
#include <stdlib.h>

// node prototype with data 
typedef struct node {
  int data;
  struct node *next;  
}node;
// definition of helper functions 
node *create_node(int data); 
void insert_at_beginning(node **head, int data); 
void display(node *head); 
void free_list(node **head);

int main() 
{
 //initialize head with null
 node *head = NULL;
// add 3 nodes 
insert_at_beginning(&head, 10);  
insert_at_beginning(&head, 20); 
insert_at_beginning(&head, 30);   

// print out the list
display(head);

// free the list 
free_list(&head); 

 return 0;
}
// node function to return back a node 
node *create_node(int data) {
  //give memory 
  node *newnode =(node*)malloc(sizeof(node));
  // give data a value
  newnode->data = data;
  // point to next node + initialize it with NULL
  newnode->next = NULL;  


  return newnode; 
}

// 
void insert_at_beginning(node **head, int data) {
  // create the node 
  node *newnode = create_node(data); 
  // point to head of the list
  newnode->next = *head;
  // newnode becomes new head
  *head = newnode; 
  
}
// parameter pointer to head because that is the starting point
void display(node *head) {
 // assigning a pointer as head to start from head
 node *current = head; 
 // traverse the list
 while (current != NULL) {
    // print the data of the current node 
    printf("%d\n", current->data);
    // change to next node 
    current = current->next; 
  } 
 // print NULL if tail reached
 printf("NULL"); 
}
// node as parameter  
void free_list(node **head) {
 // set node to head to start at beginning 
 node *current = *head;
 // pointer to next node 
 node *next; 
 // traverse 
 while (current != NULL) {
    // put pointer to next node 
    next = current->next; 
    // free memory of current node 
    free(current);
    // point to next node => needed after freeing node
    current = next; 
 }
 // point head to NULL
 *head = NULL;
  if (*head == NULL) {
    printf("\n freed and initialized head to NULL"); 
  }

}

























