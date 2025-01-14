#define _CRT_SECURE_NO_WARNINGS // Verhindert Warnungen bei der Verwendung von unsicheren Funktionen wie `strcpy`.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition der Struktur für einen Kunden
typedef struct customer {
    unsigned int customerNumber; // Kundennummer (eindeutige ID)
    char forename[40];           // Vorname des Kunden
    char surname[40];            // Nachname des Kunden
    struct customer *next;       // Zeiger auf den nächsten Kunden in der Liste
} customer;

// Funktionsprototypen
int insert(customer *, customer *);
customer *createCustomer(unsigned int, const char *, const char *);
void printList(customer *);
unsigned int customerCount(customer *);
void clearList(customer *);

// Hauptprogramm
int main(int argc, char *argv[]) {
    customer *root = NULL; // Zeiger auf den Anfang der Liste (Wurzel)

    // Erstellen der ersten Kunden und Hinzufügen zur Liste
    root = createCustomer(1, "Hans", "Maurer"); // Erster Kunde
    insert(root, createCustomer(3, "Tatjana", "Roth")); // Zweiter Kunde
    insert(root, createCustomer(2, "Anna-Maria", "Schmidt")); // Dritter Kunde

    // Ausgabe der Anzahl der Kunden und der Liste
    printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
    printList(root);

    // Liste leeren und Speicher freigeben
    clearList(root);
    root = NULL; // Sicherstellen, dass der Wurzelzeiger auf NULL zeigt

    // Überprüfen, ob die Liste wirklich leer ist
    printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
    printList(root);

    return 0;
}

// Funktion zum Einfügen eines neuen Kunden in die Liste (sortiert nach Kundennummer)
int insert(customer *root, customer *new) {
    if (root == NULL) {
        root = new; // Wenn die Liste leer ist, wird der neue Kunde die Wurzel
        return 0;
    }

    customer *current = root; // Start bei der Wurzel
    // Durchlaufen der Liste, bis der richtige Einfügepunkt gefunden ist
    while (current->next != NULL && current->next->customerNumber < new->customerNumber) {
        current = current->next; // Weiter zum nächsten Element
    }

    // Einfügen des neuen Kunden in die Liste
    new->next = current->next; // Der neue Kunde zeigt auf das nächste Element
    current->next = new;       // Der aktuelle Kunde zeigt auf den neuen Kunden

    return 0;
}

// Funktion zum Erstellen eines neuen Kunden
customer *createCustomer(unsigned int customerNumber, const char *forename, const char *surname) {
    // Speicher für den neuen Kunden allokieren
    customer *new = malloc(sizeof(customer));
    if (new == NULL) { // Überprüfen, ob die Speicherzuweisung erfolgreich war
        fprintf(stderr, "No memory left");
        return NULL;
    }

    // Initialisierung des neuen Kunden
    new->customerNumber = customerNumber; // Kundennummer setzen
    strcpy(new->forename, forename);      // Vorname kopieren
    strcpy(new->surname, surname);        // Nachname kopieren
    new->next = NULL;                     // Zeiger auf NULL setzen (Ende der Liste)

    return new; // Zeiger auf den neuen Kunden zurückgeben
}

// Funktion zur Ausgabe aller Kunden in der Liste
void printList(customer *root) {
    for (customer *current = root; current != NULL; current = current->next) {
        // Ausgabe des aktuellen Kunden
        printf("%d: %s %s\n", current->customerNumber, current->forename, current->surname);
    }
}

// Funktion zur Zählung der Kunden in der Liste
unsigned int customerCount(customer *root) {
    if (root == NULL) // Leere Liste
        return 0;

    unsigned int count = 0; // Zähler initialisieren
    customer *current = root; // Start bei der Wurzel
    while (current != NULL) { // Solange die Liste nicht zu Ende ist
        count++; // Zähler erhöhen
        current = current->next; // Zum nächsten Kunden wechseln
    }
    return count; // Anzahl der Kunden zurückgeben
}

// Funktion zum Löschen der gesamten Liste und Freigabe des Speichers
void clearList(customer *root) {
    if (root == NULL) // Leere Liste
        return;

    customer *current = root; // Start bei der Wurzel
    while (current->next != NULL) { // Solange noch Elemente vorhanden sind
        customer *next = current->next; // Zeiger auf das nächste Element speichern
        free(current); // Speicher des aktuellen Elements freigeben
        current = next; // Zum nächsten Element wechseln
    }
    free(current); // Das letzte Element freigeben
    root = NULL; // Die Wurzel auf NULL setzen
}

