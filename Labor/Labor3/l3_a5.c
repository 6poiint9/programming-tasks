#include <stdio.h>

int main()
{
    int höhe, breite;  // variablen deklarieren 
    
    // input lesen 
    scanf("%d %d", &höhe, &breite); 
    
    // schleife basiert auf höhe 
    for (int h = 0; h < höhe; h++) {
        // "+" und "-" folge für gerade zeilen 
        if (h % 2 == 0) {
            for (int b = 0; b < breite; b++) {
                if (b % 2 == 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            }
        }
        // "+" und "-" folge für ungerade zeilen 
        else { 
            for (int b = 0; b < breite; b++) {
                if (b % 2 == 0) {
                    printf("-");
                } else {
                    printf("+");
                }
            }
        }
        // neue zeilen 
        printf("\n");
    }

    return 0;
}

