#include <stdio.h>
#include <stdlib.h>
// eingegebene Int nach größe sortiert ausgeben => mit erster zahl n und Dynamischen Array  

// Funktion zur Sortierung eines Arrays (Bubble Sort)
void bubble_sort(int *numbers, int count);

int main() {
    // variable für erste Zahl n 
    int count;

    // Einlesen von n 
    scanf("%d", &count);

    // Mithilfe (count) Dynamische Speicherzuweisung für das Array 
    int *numbers = (int *)malloc(count * sizeof(int));
  // kontrolle  
  if (numbers == NULL) {
        
        return EXIT_FAILURE;
    }

    // Einlesen der Zahlen in das Array
    // Der Benutzer gibt `count` viele Zahlen => in array `numbers` gespeichert
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    // Sortieren
    bubble_sort(numbers, count);

    // Formattierte ausgabe der sortierten Zahlen mit index 
    for (int i = 0; i < count; i++) {
        printf("%2d:%4d", i + 1, numbers[i]);
    }

    // Freigabe des Speichers
    free(numbers);

    // Beenden des Programms mit Erfolgscode
    return EXIT_SUCCESS;
}

// Funktion zur Sortierung eines Arrays mithilfe (Bubble Sort) => vergleichen und tauschen
void bubble_sort(int *numbers, int count) {
    // Äußere Schleife: Iteriert über das Array für `count - 1` Durchläufe.
    for (int i = 0; i < count - 1; i++) {
        // Innere Schleife: Vergleicht und tauscht benachbarte Elemente.
        for (int j = 0; j < count - i - 1; j++) {
            // Wenn das aktuelle Element größer ist als das nächste, werden sie vertauscht.
            if (numbers[j] > numbers[j + 1]) {
                // Temporäre Variable zum Speichern des Werts von `numbers[j]`.
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

