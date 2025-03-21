#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
// wegen toupper() 
#include <ctype.h>

// Feldgröße definiert + Zeichen
#define SIZE 10
#define EMPTY '.'
#define SHIP '#'
#define HIT 'X'
#define MISS 'O'

// definition der schiffsarten + größen
#define BATTLESHIP 5  // Schlachtschiff
#define CRUISER 4     // Kreuzer
#define DESTROYER 3   // ZerstÃ¶rer
#define SUBMARINE 2   // U-Boot

// switch-case statement um schiffsname zurückzugeben, * für mehr sicherheit
const char* get_ship_type(int size) {
    switch (size) {
        case BATTLESHIP: return "Schlachtschiff";
        case CRUISER: return "Kreuzer";
        case DESTROYER: return "ZerstÃ¶rer";
        case SUBMARINE: return "U-Boot";
        default: return "Unbekanntes Schiff";
    }
}
// Funktion um zu kontrollieren ob schiff komplett zerstört wurde  
int ship_is_destroyed(char field[SIZE][SIZE], int x, int y, int *ship_type) {
    int size = 1; // Aktuelles Feld zÃ¤hlt als 1
    int temp_size = 0;
    // return 0 falls nicht zerstört und 1 falls schon
    // => jede richtung wird geprüft  

    // Nach oben prüfen
    for (int i = x - 1; i >= 0 && field[i][y] != EMPTY && field[i][y] != MISS; i--) {
        temp_size++;
        if (field[i][y] == SHIP) return 0; //Feld noch intakt
    }
    size += temp_size;

    // Nach unten prüfen
    temp_size = 0;
    for (int i = x + 1; i < SIZE && field[i][y] != EMPTY && field[i][y] != MISS; i++) {
        temp_size++;
        if (field[i][y] == SHIP) return 0;
    }
    size += temp_size;

    // Nach links prüfen
    temp_size = 0;
    for (int j = y - 1; j >= 0 && field[x][j] != EMPTY && field[x][j] != MISS; j--) {
        temp_size++;
        if (field[x][j] == SHIP) return 0;
    }
    size += temp_size;

    // Nach rechts prüfen
    temp_size = 0;
    for (int j = y + 1; j < SIZE && field[x][j] != EMPTY && field[x][j] != MISS; j++) {
        temp_size++;
        if (field[x][j] == SHIP) return 0;
    }
    size += temp_size;
    
  // falls kein intaktes schiff gefunden 
  // speichert größe
    *ship_type = size;
    return 1; // Schiff zerstÃ¶rt
}

// bearbeitet die Nutzer Eingaben und koordinaten  
void parse_coordinates(const char *coord, int *x, int *y) {
    // SPALTE bestimmen (A bis J)
    *y = toupper(coord[0]) - 'A';
    if (*y < 0 || *y >= SIZE) {
        // falls ungültige koord. eingegeben 
        printf("UngÃ¼ltige Spalte: %c\n", coord[0]);
        *x = -1; *y = -1;
        return;
    }

    // ZEILE bestimmen (1 bis 10)
    int row = 0;
    if (sscanf(coord + 1, "%d", &row) != 1 || row < 1 || row > SIZE) {
        printf("UngÃ¼ltige Zeile: %s\n", coord + 1);
        *x = -1; *y = -1;
        return;
    }

    // Zeile in 0-basierten Index konvertieren
    *x = row - 1;
}

// Feld initalisieren mit Empty -> '.'
void init_field(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = EMPTY;
        }
    }
}
// Funktion für die Ausgabe der Feldes
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

// Funktion für platzierung der schiffe 
void read_ship_positions_from_input(char field[SIZE][SIZE]) {
    char input[20];
    while (1) {
        scanf("%19s", input);
        // falls (e) dann schießen     
        if (strcmp(input, "e") == 0) {
            break; 
        }

        char start[5] = {0}, end[5] = {0}; 
        char *dash = strchr(input, '-'); // Trennungszeich in der Eingabe finden
         
        // kontrolle trennungszeichen
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

// Funktion für Schießen und verarbeitung der schüsse 
void play_game(char field[SIZE][SIZE], int *hits, int *shots) {
    char input[10];
    // zuerst mit 0 initialisiert
    int total_ship_parts = 0;
    // Schleife um schiffe zu zählen 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == SHIP) {
                total_ship_parts++;
            }
        }
    }
    // while schleife für nutzereingabe schießen
    while (1) {
        scanf("%s", input);
        // Spiel beenden falls (x) eingegeben 
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
        // schuss-zähler 
        (*shots)++;
        // Falls getroffen 
        if (field[x][y] == SHIP) {
            field[x][y] = HIT;
            (*hits)++;
            int ship_size = 0;
            if (ship_is_destroyed(field, x, y, &ship_size)) {
                printf("%s Getroffen! %s wurde versenkt!\n", input, get_ship_type(ship_size));
            } else {
                printf("%s Getroffen!\n", input);
            }

            //Beenden falls alle schiffe versenkt wurden
            if (*hits == total_ship_parts) {
                printf("\nAlle Schiffe wurden versenkt\n\n");
                break;
            }
        // Falls fehlschuss
        } else if (field[x][y] == EMPTY) {
            field[x][y] = MISS;
            printf("%s Fehlschuss!\n", input);
        // kontrolle ob MISS nochmal angeschossen wurde
        } else {
            printf("Diese Position wurde bereits beschossen.\n");
        }
    }
}
// Funktion um das Finale feld und die Trefferquote zurückzugeben
void evaluate_and_print_results(char field[SIZE][SIZE], int hits, int shots) {
    print_field(field);
    // mit ternary operator falls nichts getroffen wurde und => nicht durch 0 teilen
    double accuracy = (shots > 0) ? ((hits / (double)shots) * 100.0) : 0.0; 
    printf("Trefferquote: %.0lf%%\n", accuracy);
}

// ------------------- MAIN ----------------------------------
int main() {
    int hits = 0;
    int shots = 0;
    //feld wird mit 10*10 initialisiert
    char field[SIZE][SIZE];
    // pass by value => feld-basierte funktionen mit SIZE initialisiert, schuss basierte mit 0
    // basis Feld initialisiert 
    init_field(field);
    // nutzer eingabe platzieren
    read_ship_positions_from_input(field);
    // ausgabe platziere schiffe
    print_field(field);
    // nutzer eingabe schießen
    play_game(field, &hits, &shots);
    // ausgabe endfeld und Trefferquote 
    evaluate_and_print_results(field, hits, shots);
    return 0;
}

