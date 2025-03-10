/*
Prioritäts warteschlange  

- prio ist 0 bis 5 niedrig 

Funktionen:

addNewNode() =
- typ node ptr
- erstellt + fügt node der liste hinzu basierend auf prio
=> bei gleicher prio neu vor alt 
- return ist pointer auf neuen node 


deleteNodes() =
- löscht node basierend auf prio 
- return pointer auf die liste
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  // priorität 
  int priority;
  double data; 
  struct node *next; // pointer auf nächsten node 
}node; 

// Funtion prototypen 
node *addNewNode(node **head, int priority, double data);
node *deleteNodes(node **head, int prio); 

// main Funktion 
int main()
{
  // head pointer mit NULL initialisieren
  node *head = NULL;
  
  // daten übergeben 
  addNewNode(&head, 3, 6.9); 
  addNewNode(&head, 5, 7.7); 
  addNewNode(&head, 0, 6.9);
  addNewNode(&head, 3, 5.5);

  // Paar Nodes löschen 
  deleteNodes(&head, 3);
  deleteNodes(&head, 0); 
 

  return 0; 
}

node *addNewNode(node **head, int priority, double data) {
  // newnode initialisieren
  node *newnode = NULL; 

  // newnode speicher geben
  newnode = (node*)malloc(sizeof(node)); 
  // kontrolle ob speicherzuweisung erfolgt 
  if (newnode == NULL) {
    printf("malloc fehlgeschlagen");
    return NULL; 
  }
  // data zuweisen 
  newnode->priority = priority;
  newnode->data = data;

  // pointer auf nächsten node mit NULL initialisieren
  newnode->next = NULL; 
  // testen ob liste Leer oder head node niedrigere priority
  if (*head == NULL || (*head)->priority > priority ) {
    newnode->next = *head;   
    newnode = *head; 
  } else {
    // current node auf head um von anfang zu beginnen 
    node *current = *head; 
    // traversieren
    // bis auf null und prio vergleichen
    while (current->next != NULL && current->next->priority <= priority) {
      // auf nächsten node wechseln
      current = current->next;     
    }
   // Merke vorherigen nächsten Knoten um rest der Liste zu erhalten 
   newnode->next = current->next;
     // setze neuen Knoten als nächsten Knoten des aktuellen Knotens
   current->next = newnode; 
   }
  return *head; 
 }


node *deleteNodes(node **head, int priority) {
    if (*head == NULL) {
        return NULL; // Liste ist leer
    }

    // Knoten am Anfang der Liste löschen, falls die Priorität übereinstimmt
    while (*head != NULL && (*head)->priority == priority) {
        node *temp = *head;
        *head = (*head)->next; // Kopf der Liste aktualisieren
        free(temp); // Speicher freigeben
    }

    // Rest der Liste traversieren
    node *current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->priority == priority) {
            node *temp = current->next;
            current->next = current->next->next; // Knoten aus der Liste entfernen
            free(temp); // Speicher freigeben
        } else {
            current = current->next; // Zum nächsten Knoten wechseln
        }
    }

    return *head;
}


































