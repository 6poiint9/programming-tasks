/*
Linked list sorted by priority number 

Functions:

createNode() => creates and returns a node 

addNode() => adds a node to the list based on priority -> check if list empty 

deletenode() => deletes node based on priority -> check if list empty 

printQueue() => prints out the node values 

printNodenumber() => prints out number of nodes 

deleteList() => deletes whole list and frees memory 

*/
#include <stdio.h>
#include <stdlib.h>

// structure prototype 
typedef struct node {
 // variable that stored priority
 int priority;
 // data variable 
 double data; 
 // pointer to next node
 struct node *next; 

}node;

// Function prototypes 
node *createNode(int priority, double data); 
void addNode(node **head, int priority, double data);
void deletenode(node **head, int priority); 
void printQueue(node *head);
void printNodenumber(node *head); 
void deletelist(node **head); 

int main()
{
  // initialize head pointer to NULL  
  node *head = NULL; 
  
  // pass data and priority values to create a Node 
  addNode(&head, 0, 6.9);  // Add node with priority 0 and data 6.9
  addNode(&head, 3, 5.5);  // Add node with priority 3 and data 5.5
  addNode(&head, 1, 8.8);  // Add node with priority 1 and data 8.8
  addNode(&head, 1, 9.6);  // Add node with priority 1 and data 9.6 
  // Print out number and data of nodes
  printQueue(head);
  printNodenumber(head); 

  // Pass values to delete specific node 
  deletenode(&head, 3); 
  deletenode(&head, 0); 
  
  // print data and number after deleting some nodes 
  printQueue(head);
  printNodenumber(head); 
  
  // Delete and free the whole List 
  deletelist(&head); 

  // print number of nodes after deleting whole list
  printNodenumber(head); 


  return 0;
}


node *createNode(int priority, double data) {
  // initialize newnode 
  node *newnode = NULL; 
  // allocate memory 
  newnode = (node*)malloc(sizeof(node)); 
  // check if allocation successfull
  if (newnode == NULL) {
    printf("allocation failed");
    // how to return something ? 
   }
  // assign the data 
  newnode->priority = priority; 
  newnode->data = data;
  
  // return the node 
  return newnode; 
} 

void addNode(node **head, int priority, double data) {
  // get and initialize newnode 
  node *newnode = createNode(priority, data); 
  
  // check if the list is empty or the head node has a lower priority
  if (*head == NULL || (*head)->priority > priority) {
    // if that is the case make newnode the new head 
    newnode->next = *head;
    *head = newnode; 
  }
  else {
   // initialize a node to head to Traverse list from beginning 
   node *current = *head;  
   // Traverse list and compare priority 
   while (current->next != NULL && current->next->priority <= priority) {
    // keep checking the nodes  
    current = current->next; 
    }
    // insert newnode and re-align the list 
    newnode->next = current->next; 
    current->next = newnode; 
  } 
}

void deletenode(node **head, int priority) {
   // if list is empty exit 
   if (*head == NULL) {
    return; 
  }
   // For Head node 
   // check if head node matches the priority to be deleted 
    while (*head != NULL && (*head)->priority == priority) {
        // store *head in a temporary pointer in case it will be freed
        node *temp = *head; 
        *head = (*head)->next; // traverse to next node  
        free(temp); // free/delete head if priority matches 
    }

   // For Rest of the nodes 
  // ititialize node to head to traverse from beginning
  node *current = *head;
  // ititialize a temporary node 
  node *temp = NULL;
  // traverse whole list 
  while (current != NULL && current->next != NULL) {
    // check if priority matches 
    if ( current->next->priority == priority) {
      // save the node in temp to delete  
      temp = current->next; 
      // re-align the list 
      current->next = current->next->next;
      // free memory of the node to delete 
      free(temp);
    } 
    else {
      // change to next node 
      current = current->next; 
    }   
  }  
}

void printQueue(node *head) {
 // check if list is empty 
 if (head == NULL) {
    return;
  }
 // initialize node pointer to head before traversing
 node *current = head;
 
 // travers list 
 while (current != NULL) {
    // print out data of current node 
    printf("\n%f", current->data); 
    // move to next node 
    current = current->next;
  }
  // print NULL if end of list reached
  printf("\nNULL");
}

void printNodenumber(node *head) {
  // check if List empty
  if (head == NULL) {
    return; 
  }
  // ititialize node to head 
  node *current = head; 

  // create variable for counting
  int count = 0; 
  // traverse list 
  while (current != NULL) {
    count++; // count
    current = current->next; // move to next node 
  }
  // print number of nodes
  printf("\nthere are currently %d nodes", count); 
}

void deletelist(node **head) {
  // check if list is empty 
  if (*head == NULL) {
    return;
  }
  // initialize pointer to head 
  node *current = *head;
  
  // create a variable to store address of next node 
  node *nextnode = NULL;
  // traverse List + Delete/free nodes
  while (current != NULL) {
    // save address of next node before freeing 
    current->next = nextnode; 
    free(current); // free the node 
    current = nextnode; // go on to next node 
  }
 // initialize head back to NULL
 *head = NULL; 

}

