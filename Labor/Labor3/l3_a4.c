#include <stdio.h>

int main() {
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    for (int i = 0; i < rows; i++) {

        if (i == 0 || i == rows - 1) {
            for (int j = 0; j < columns; j++) {
                printf("*");
            }
        }
        
        else {
            printf("*");  // Print the first star
            for (int j = 1; j < columns - 1; j++) {
                printf(" ");  // Print spaces in between
            }
            if (columns > 1) {
                printf("*");  // Print the last star (only if columns > 1)
            }
        }
        printf("\n");  // Newline after each row
    }

    return 0;
}
