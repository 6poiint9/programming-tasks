#include <stdio.h>
// Programm das ein Rechteck mit der Größe N erzeugt und den innenraum mit einem Kreuz ausfüllt
int main() {
    // Variable für eingabe 
    int eingabe;
    
    // Nutzer eingabe lesen
    scanf("%d", &eingabe);
    
    // Schleife 
    for (int h = 0; h < eingabe; h++) {
        for (int w = 0; w < eingabe; w++) {
            // Erste und letzte zeile 
            if (h == 0 || h == eingabe - 1) {
                printf("*");
            }
            // Mittlere zeilen 
            else {
                // "Eck-Säulen" 
                if (w == 0 || w == eingabe - 1) {
                    printf("*");
                }
                // diagonale sterne 
                else if (w == h || w == eingabe - h - 1) {
                    printf("*");
                }
                // "Platz" drucken 
                else {
                    printf(" ");
                }
            }
        }
        // Neue zeilen 
        printf("\n");
    }

    return 0;
}
