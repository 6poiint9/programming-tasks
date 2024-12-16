#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define EMPTY '.'
#define SHIP '#'
#define HIT 'X'
#define MISS 'O'

#define BATTLESHIP 5  // Schlachtschiff
#define CRUISER 4     // Kreuzer
#define DESTROYER 3   // ZerstÃ¶rer
#define SUBMARINE 2   // U-Boot

const char* get_ship_type(int size) {
    switch (size) {
        case BATTLESHIP: return "Schlachtschiff";
        case CRUISER: return "Kreuzer";
        case DESTROYER: return "ZerstÃ¶rer";
        case SUBMARINE: return "U-Boot";
        default: return "Unbekanntes Schiff";
    }
}

int ship_is_destroyed(char field[SIZE][SIZE], int x, int y, int *ship_type) {
    int size = 1; // Aktuelles Feld zÃ¤hlt als 1
    int temp_size = 0;

    // Nach oben prÃ¼fen
    for (int i = x - 1; i >= 0 && field[i][y] != EMPTY && field[i][y] != MISS; i--) {
        temp_size++;
        if (field[i][y] == SHIP) return 0; //Feld noch intakt
    }
    size += temp_size;

    // Nach unten prÃ¼fen
    temp_size = 0;
    for (int i = x + 1; i < SIZE && field[i][y] != EMPTY && field[i][y] != MISS; i++) {
        temp_size++;
        if (field[i][y] == SHIP) return 0;
    }
    size += temp_size;

    // Nach links prÃ¼fen
    temp_size = 0;
    for (int j = y - 1; j >= 0 && field[x][j] != EMPTY && field[x][j] != MISS; j--) {
        temp_size++;
        if (field[x][j] == SHIP) return 0;
    }
    size += temp_size;

    // Nach rechts prÃ¼fen
    temp_size = 0;
    for (int j = y + 1; j < SIZE && field[x][j] != EMPTY && field[x][j] != MISS; j++) {
        temp_size++;
        if (field[x][j] == SHIP) return 0;
    }
    size += temp_size;

    *ship_type = size;
    return 1; // Schiff zerstÃ¶rt
}

void parse_coordinates(const char *coord, int *x, int *y) {
    // Spalte bestimmen (A bis J)
    *y = toupper(coord[0]) - 'A';
    if (*y < 0 || *y >= SIZE) {
        printf("UngÃ¼ltige Spalte: %c\n", coord[0]);
        *x = -1; *y = -1;
        return;
    }

    // Zeile bestimmen (1 bis 10)
    int row = 0;
    if (sscanf(coord + 1, "%d", &row) != 1 || row < 1 || row > SIZE) {
        printf("UngÃ¼ltige Zeile: %s\n", coord + 1);
        *x = -1; *y = -1;
        return;
    }

    // Zeile in 0-basierten Index konvertieren
    *x = row - 1;
}

void init_field(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = EMPTY;
        }
    }
}

void print_field(char field[SIZE][SIZE]) {
    printf("  ABCDEFGHIJ\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

/* Hauptproblem bei der Bearbeitung der Aufgabe: 
    * 10. Zeile wurde nicht eingelesen,
    * LÃ¶sungen: ErhÃ¶hung der BuffergrÃ¶ÃŸe der Start- und Endkoordinaten
    * Suche der Trennungszeichen, um die Eingabe korrekt zu implementieren
*/

void read_ship_positions_from_input(char field[SIZE][SIZE]) {
    char input[20];
    while (1) {
        scanf("%19s", input);

        if (strcmp(input, "e") == 0) {
            break; // Spiel starten
        }

        char start[5] = {0}, end[5] = {0}; // BuffergrÃ¶ÃŸe wird auf 5 erhÃ¶ht
        char *dash = strchr(input, '-'); // Trennungszeich in der Eingabe finden

        if (dash) {
            // Eingabe manuell aufteilen
            *dash = '\0';  // '-' durch Null-Terminator ersetzen
            strcpy(start, input); // Startkoordinaten werden kopiert
            strcpy(end, dash + 1); // Endkoordinaten werden kopiert
        } else {
            printf("Falsches Format. Bitte erneut versuchen.\n");
            continue;
        }

        int x1, y1, x2, y2;

        parse_coordinates(start, &x1, &y1);
        parse_coordinates(end, &x2, &y2);

        if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
            printf("UngÃ¼ltige Koordinaten. Bitte erneut versuchen.\n");
            continue;
        }

        if (x1 == x2) { // Horizontal
            if (y1 > y2) { int temp = y1; y1 = y2; y2 = temp; }
            for (int j = y1; j <= y2; j++) {
                field[x1][j] = SHIP;
            }
        } else if (y1 == y2) { // Vertikal
            if (x1 > x2) { int temp = x1; x1 = x2; x2 = temp; }
            for (int i = x1; i <= x2; i++) {
                field[i][y1] = SHIP;
            }
        } else {
            printf("UngÃ¼ltige Eingabe: Die Positionen mÃ¼ssen in einer Linie liegen.\n");
        }
    }
}


void play_game(char field[SIZE][SIZE], int *hits, int *shots) {
    char input[10];
    int total_ship_parts = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == SHIP) {
                total_ship_parts++;
            }
        }
    }

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "x") == 0) {
            printf("\nDas Spiel wurde beendet.\n\n");
            break;
        }

        int x, y;
        parse_coordinates(input, &x, &y);

        if (x == -1 || y == -1) {
            printf("UngÃ¼ltige Eingabe. Bitte erneut versuchen.\n");
            continue;
        }

        (*shots)++;

        if (field[x][y] == SHIP) {
            field[x][y] = HIT;
            (*hits)++;
            int ship_size = 0;
            if (ship_is_destroyed(field, x, y, &ship_size)) {
                printf("%s Getroffen! %s wurde versenkt!\n", input, get_ship_type(ship_size));
            } else {
                printf("%s Getroffen!\n", input);
            }

            //PrÃ¼fung, ob alle Schiffe versenkt wurden
            if (*hits == total_ship_parts) {
                printf("\nAlle Schiffe wurden versenkt\n\n");
                break;
            }
        } else if (field[x][y] == EMPTY) {
            field[x][y] = MISS;
            printf("%s Fehlschuss!\n", input);
        } else {
            printf("Diese Position wurde bereits beschossen.\n");
        }
    }
}

void evaluate_and_print_results(char field[SIZE][SIZE], int hits, int shots) {
    print_field(field);
    double accuracy = (shots > 0) ? ((hits / (double)shots) * 100.0) : 0.0; //TernÃ¤ren Operator: Vermeiden, um durch 0 zu teilen
    printf("Trefferquote: %.0lf%%\n", accuracy);
}

int main() {
    int hits = 0;
    int shots = 0;
    char field[SIZE][SIZE];
    init_field(field);
    read_ship_positions_from_input(field);
    print_field(field);
    play_game(field, &hits, &shots);
    evaluate_and_print_results(field, hits, shots);
    return 0;
}

