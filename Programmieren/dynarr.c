/*
Dynamisches Int-array als linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct num {
 int data; 
 struct num *next; 
} num;

// Funktion prototypen
void append(num **head, int data);
void print(num *head); 
void clear(num **head); 

int main()
{
  // head pointer mit NULL initialisieren
  num *root = NULL;
  // pass data and address 
  append(&root, 42);
  append(&root, 1);
  append(&root, 2);
  append(&root, 3);
  
  // ausgabe der daten aller member
  print(root); 
  
  // befreiung des speichers 
  clear(&root); 

  return 0;
}

void append(num **head, int data) {
  // create newnode pointer 
  num *newnode = NULL;
  // allocate memory 
  newnode=(num*)malloc(sizeof(num));
  // check if allocation failed
  if (newnode == NULL) {
    printf("allocation failed");
    return;  
  }
  
  // assign data to new node 
  newnode->data = data;
  // Newnode next should be NULL because last 
  newnode->next = NULL; 

  // check if List empty
  if (*head == NULL) {
    // newnode becomes head 
    *head = newnode;
  }
  else {
   // temporary pointer to head for traversal
   num *temp = *head; 
   // traverse till tail 
   while (temp->next != NULL) {
    // change to next next node 
    temp = temp->next; 
  }
   // assign tempnode to newnode 
   temp->next = newnode;
  }

}

void print(num *head) {
  // assign pointer to head
  num *current = head;
  
  // traverse the list
  while (current != NULL) {
    // print out stuff from current node
    printf("\n%d", current->data); 
    // change current to next node 
    current = current->next; 
  }
  // if tail reached 
  printf("NULL"); 
} 


void clear(num **head) {
  // assign pointer to head to start from beginning
  num *current = *head; 
  // to change after freeing
  num *next = NULL; 
  
  // traverse 
  while (current != NULL) {
    // store address of the next node to next before freeing  
    next = current->next;
    // free current 
    free(current);
    // assign next node address to current 
    current = next; 
  }

  // point head to NULL
  *head = NULL; 
} 
 













