/*
Kundenmanagement system

=> Speicher Kunden in linked list 

Funktionen:

addCustomer() =
- erstellt + fügt kunden/nodes der liste hinzu 
- hinzufügen nach nummer 

print() =
- ausgabe ALLER kunder/daten der member 

customerCount() =
- Zählt anzahl der Kunden/nodes
- gibt anzahl aus 

clearList() =
- Liste wird geleert + alles gelöscht -> speicher freigeben
- free aller nodes 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node prototyp erstellen
typedef struct kunde {
 // struct member
  int id;
  // vor und nachname
  char *vor;
  char *nach; 
  // pointer auf next node
  struct kunde *next; 
}kunde; 

// Funktion prototypen
void addCustomer(kunde **head, int id,const char *vor,const char *nach); 
void print(kunde *head); 
void customerCount(kunde *head); 
void clearList(kunde **head); 

// anfang main funktion 
int main()
{
  // pointer für head node mit NULL initialisieren
  kunde *head = NULL; 

  // Kunden erstellen übergabe
  addCustomer(&head, 1, "Hans", "Maurer"); 
  addCustomer(&head, 4, "Karl-Heinz", "Menauer");
  addCustomer(&head, 3, "travis", "doom");

  // Ausgabe der Kunden Anzahl
  customerCount(head); 
  
  // Ausgabe der Kunden 
  print(head); 

  // Freigabe Speicher der Nodes / Löschen der Kunden
  clearList(&head); 

  // Ausgabe der Anzahl nach dem Löschen 
  customerCount(head); 

  return 0; 
}


void addCustomer(kunde **head, int id,const char *vor,const char *nach) {
  // pointer auf node initialisieren
  kunde *newnode = NULL; 
  
  // node erstellen
  // speicher geben
  newnode =(kunde*)malloc(sizeof(kunde));  
  // kontrolle ob speicher zuweisung erfolgreich
  if (newnode == NULL) {
    printf("speicher zuweisung fehlgeschlagen");
    return; 
   }
  // allcoate data
  newnode->id = id;
  // für char arrays nochmal speicher geben
  newnode->vor = (char *)malloc(strlen(vor) + 1); 
   if (newnode->vor == NULL) {
    printf("malloc failed");
    return; 
  }

  newnode->nach = (char *)malloc(strlen(nach) + 1); 
   if (newnode->nach == NULL) {
    printf("malloc failed");
    return; 
  }
  // strings rein kopieren
  strcpy(newnode->vor, vor);
  strcpy(newnode->nach, nach); 


  // implement sorting stuff based on id
  // initialise with null to avoid dangling 
  newnode->next = NULL; 
  // If list empty become new head 
  if (*head == NULL || (*head)->id > id) {
    newnode->next = *head;
    *head = newnode; 
  } else {
    // einen node pointer auf head initialieren um liste von begin zu traversieren
    kunde *current = *head; 
    // Traversieren und id vergleichen 
    while (current->next != NULL && current->next->id < id) {
      current = current->next; 
    }
    newnode->next = current->next; 
    current->next = newnode; 
   } 
} 

void print(kunde *head) {
  // struct pointer auf head initialisieren um list von beginn zu traversieren
  kunde *current = head; 
  // traversieren
  while (current != NULL) {
    // daten ausgeben
    printf("\n%d: %s %s", current->id, current->vor, current->nach); 
    // auf nächsten node wechseln 
    current = current->next; 
  }
} 

void customerCount(kunde *head) {
  // struct pointer auf head 
  kunde *current = head;
  // int zum zählen
  int count = 0; 
  // traversieren
  while (current != NULL) {
   count++; 
   current = current->next;  
  }
  printf("\nMomentan sind %d Kunden erfasst.",count); 
} 

void clearList(kunde **head) {
  // p auf head 
  kunde *current = *head; 
  // temporärer node pointer
  kunde *next; 
  // traverse 
  while(current != NULL) {
    // adresse vom nächsten node in temp speichern 
    current->next = next;
    // free
    free(current); 
    // current auf nächsten node zeigen
    current = next; 
  }
  // head auf NULL zeigen lassen 
  *head = NULL; 
} 


