#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

// Struct to represent a ship
typedef struct {
    char type[20];
    int size;
    int remaining;
    int placed; // Whether the ship has been fully placed
} Ship;

// Function prototypes
void input(char shipsBoard[ROWS][COLUMNS], char shotsBoard[ROWS][COLUMNS], Ship ships[], int *shipCount, int *hits, int *shots);
void Brett(char board[ROWS][COLUMNS]);
void placeShip(char board[ROWS][COLUMNS], const char *start, const char *end, Ship *ship);
void updateShotBoard(char shipsBoard[ROWS][COLUMNS], char shotsBoard[ROWS][COLUMNS], const char *coord, Ship ships[], int shipCount, int *hits, int *shots);
int validatePlacement(const char *start, const char *end, int *length);

int main() {
    // Initialize the boards
    char shipsBoard[ROWS][COLUMNS];  // Board for ship placement
    char shotsBoard[ROWS][COLUMNS]; // Board for hit/miss tracking

    // Fill both boards with '.'
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            shipsBoard[i][j] = '.'; // Empty space
            shotsBoard[i][j] = '.'; // Empty space
        }
    }

    // Initialize ships
    Ship ships[10]; // A maximum of 10 ships
    int shipCount = 0;
    int hits = 0, shots = 0;

    // Input phase: users place ships and take shots
    input(shipsBoard, shotsBoard, ships, &shipCount, &hits, &shots);

    // Print final boards
    printf("\nFinal Shots Board:\n");
    Brett(shotsBoard);

    printf("\nFinal Ships Board:\n");
    Brett(shipsBoard);

    // Print hit rate
    if (shots > 0) {
        double accuracy = (double)hits / shots * 100;
        printf("\nTrefferquote: %.2f%%\n", accuracy);
    } else {
        printf("\nKeine Schüsse abgefeuert.\n");
    }

    return 0;
}

// Function to handle user input
void input(char shipsBoard[ROWS][COLUMNS], char shotsBoard[ROWS][COLUMNS], Ship ships[], int *shipCount, int *hits, int *shots) {
    char stuff[20];
    printf("Enter ship coordinates to place ships (e.g., A1-A4), 'e' to start shooting, 'x' to end.\n");

    int placingShips = 1; // Flag for ship placement phase

    while (1) {
        scanf("%19s", stuff);

        // Check for 'x' to terminate input
        if (strcmp(stuff, "x") == 0) {
            printf("Das Spiel wurde beendet.\n");
            break;
        }

        // Check for 'e' to switch to shooting phase
        if (strcmp(stuff, "e") == 0) {
            printf("Jetzt schießen!\n");
            placingShips = 0; // Switch to shooting phase
            continue;
        }

        // Handle input based on current phase
        if (placingShips) {
            // Ship placement phase
            char start[4], end[4];
            int length = 0;

            if (strchr(stuff, '-')) {
                // Parse range (e.g., A1-A3)
                sscanf(stuff, "%[^-]-%s", start, end);

                // Validate range
                if (!validatePlacement(start, end, &length)) {
                    printf("Ungültige Eingabe: %s\n", stuff);
                    continue;
                }

                Ship ship;
                ship.size = length;
                ship.remaining = length;
                ship.placed = 1;

                // Automatically determine the ship type based on its size
                if (length == 5) {
                    strcpy(ship.type, "Schlachtschiff");
                } else if (length == 4) {
                    strcpy(ship.type, "Kreuzer");
                } else if (length == 3) {
                    strcpy(ship.type, "Zerstörer");
                } else if (length == 2) {
                    strcpy(ship.type, "U-Boot");
                } else {
                    printf("Ungültige Schiffgröße: %d\n", length);
                    continue;
                }

                // Place the ship on the board
                placeShip(shipsBoard, start, end, &ship);
                ships[(*shipCount)++] = ship;

            } else {
                printf("Ungültiger Bereich: %s\n", stuff);
            }
        } else {
            // Shooting phase
            updateShotBoard(shipsBoard, shotsBoard, stuff, ships, *shipCount, hits, shots);
        }
    }
}

// Function to print a board
void Brett(char board[ROWS][COLUMNS]) {
    // Print column headers
    printf("  ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c", c);
    }
    printf("\n");

    // Print rows with row numbers
    for (int i = 0; i < ROWS; i++) {
        printf("%2d", i + 1); // Print row number
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", board[i][j]); // Print board content
        }
        printf("\n");
    }
}

// Function to place a ship on the board
void placeShip(char board[ROWS][COLUMNS], const char *start, const char *end, Ship *ship) {
    int startRow = start[1] - '1';  // Convert start row from char to int
    int startCol = start[0] - 'A';  // Convert start column letter to 0-based index
    int endRow = end[1] - '1';      // Convert end row from char to int
    int endCol = end[0] - 'A';      // Convert end column letter to 0-based index

    if (startRow == endRow) {
        // Horizontal placement
        for (int col = startCol; col <= endCol; col++) {
            board[startRow][col] = '#';
        }
    } else if (startCol == endCol) {
        // Vertical placement
        for (int row = startRow; row <= endRow; row++) {
            board[row][startCol] = '#';
        }
    }
}

// Function to update the shots board
void updateShotBoard(char shipsBoard[ROWS][COLUMNS], char shotsBoard[ROWS][COLUMNS], const char *coord, Ship ships[], int shipCount, int *hits, int *shots) {
    int row = coord[1] - '1';  // Convert row number from char to int (0-based index)
    int col = coord[0] - 'A';  // Convert column letter to 0-based index

    (*shots)++;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLUMNS) {
        if (shipsBoard[row][col] == '#') {
            // Hit
            shipsBoard[row][col] = 'X'; // Mark as hit on ship board
            shotsBoard[row][col] = 'X'; // Mark as hit on shots board
            (*hits)++;
            printf("%s Getroffen!\n", coord);

            // Check if a ship was sunk
            for (int i = 0; i < shipCount; i++) {
                if (ships[i].placed && ships[i].remaining > 0) {
                    ships[i].remaining--;
                    if (ships[i].remaining == 0) {
                        printf("%s wurde versenkt!\n", ships[i].type);
                    }
                    break;
                }
            }
        } else {
            // Miss
            shotsBoard[row][col] = 'O'; // Mark as miss
            printf("%s Fehlschuss!\n", coord);
        }
    } else {
        printf("Ungültige Koordinate: %s\n", coord);
    }
}

// Function to validate ship placement and calculate the ship's length
int validatePlacement(const char *start, const char *end, int *length) {
    if (strlen(start) < 2 || strlen(end) < 2) return 0;

    int startRow = start[1] - '1';
    int startCol = start[0] - 'A';
    int endRow = end[1] - '1';
    int endCol = end[0] - 'A';

    if (startRow == endRow) {
        *length = abs(endCol - startCol) + 1;
    } else if (startCol == endCol) {
        *length = abs(endRow - startRow) + 1;
    } else {
        return 0; // Invalid: neither horizontal nor vertical
    }

    return (*length >= 2 && *length <= 5);
}

