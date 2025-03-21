#include <stdio.h>
// Funktion die überprüft ob eine genzzahl Primzahl ist oder nicht
// Ja = 1, Nein = 0

int prime(int num) {
    // Negative Zahlen, 0 und 1 sind keine Primzahlen
    if (num <= 1) {
        return 0;
    }

    // Schleife, um die Zahl zu prüfen
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) { // Wenn teilbar, dann keine Primzahl
            return 0;
        }
    }

    return 1; // Ist eine Primzahl
}

// 



//Ausgabe

int main() 
{
 printf(prime(2) ? "Primzahl" : "KEINE Primzahl");
 return 0;
}




