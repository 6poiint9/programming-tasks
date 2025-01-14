#include <stdio.h>
#include <stdlib.h>
// dynamisches Integer-Array mithilfe einer einfach verketteten Liste.

// Definition der Struktur für ein Element der verketteten Liste
typedef struct numberItem {
    int value;                  // Wert des Elements
    struct numberItem *next;    // Zeiger auf das nächste Element in der Liste
} numberItem;

// Funktion zum Anhängen eines Elements an die verkettete Liste
void append(numberItem **root, int value) {
    // Speicher für ein neues Element allokieren
    numberItem *newItem = (numberItem *)malloc(sizeof(numberItem));
    if (newItem == NULL) {
        // Wenn die Speicherzuweisung fehlschlägt, eine Fehlermeldung ausgeben
        printf("Speicher konnte nicht zugewiesen werden.\n");
        return;
    }

    // Das neue Element initialisieren
    newItem->value = value;  // Den Wert setzen
    newItem->next = NULL;    // Das neue Element zeigt auf kein weiteres Element (Ende der Liste)

    if (*root == NULL) {
        // Falls die Liste leer ist, wird das neue Element zur Wurzel (Anfang der Liste)
        *root = newItem;
    } else {
        // Andernfalls durchläuft man die Liste bis zum letzten Element
        numberItem *current = *root;
        while (current->next != NULL) {
            current = current->next;
        }
        // Das neue Element wird am Ende der Liste angehängt
        current->next = newItem;
    }
}

// Funktion zur Ausgabe aller Elemente der Liste
void print(numberItem *root) {
    // Start bei der Wurzel der Liste
    numberItem *current = root;
    while (current != NULL) {
        // Den Wert des aktuellen Elements ausgeben
        printf("%d\n", current->value);
        // Zum nächsten Element wechseln
        current = current->next;
    }
}

// Funktion zum Freigeben des Speichers aller Elemente in der Liste
void clear(numberItem **root) {
    numberItem *current = *root;  // Start bei der Wurzel der Liste
    while (current != NULL) {
        // Temporäre Speicherung des aktuellen Elements
        numberItem *temp = current;
        // Zum nächsten Element wechseln
        current = current->next;
        // Speicher des aktuellen Elements freigeben
        free(temp);
    }
    // Nach dem Löschen aller Elemente wird die Wurzel auf NULL gesetzt
    *root = NULL;
}

