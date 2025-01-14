#include <stdio.h>
// 2 Brüche sollen miteinander Multipliziert und dividiert werden

// Definition der Struktur für einen Bruch
typedef struct {
    int zaehler;  // Der Zähler des Bruchs
    int nenner;   // Der Nenner des Bruchs
} Bruch;

// Funktion für Multiplikation 
Bruch multipliziere(Bruch a, Bruch b) {
    // Erzeugt ein neues Bruch-Objekt, das das Produkt der beiden Brüche speichert
    Bruch ergebnis;
    ergebnis.zaehler = a.zaehler * b.zaehler; // Multipliziert die Zähler
    ergebnis.nenner = a.nenner * b.nenner;   // Multipliziert die Nenner
    return ergebnis; // Gibt Bruch zurück
}

// Funktion für Division
Bruch dividiere(Bruch a, Bruch b) {
    // wegen kehrwert
    // Erzeugt ein neues Bruch-Objekt, das den Quotienten der beiden Brüche speichert
    Bruch ergebnis;
    ergebnis.zaehler = a.zaehler * b.nenner; // Multipliziert den Zähler des ersten Bruchs mit dem Nenner des zweiten Bruchs
    ergebnis.nenner = a.nenner * b.zaehler; // Multipliziert den Nenner des ersten Bruchs mit dem Zähler des zweiten Bruchs
    return ergebnis; // Gibt den resultierenden Bruch zurück
}

// Funktion für Ausgabe und formatierung
void druckeBruch(Bruch b) {
    // Gibt Bruch formattiert aus
    printf("(%d.0/%d.0)", b.zaehler, b.nenner);
}

int main() {
    // Deklaration der Variablen 
    Bruch bruch1, bruch2, produkt, quotient;

    // Eingabe Brüche 
    scanf("%d/%d", &bruch1.zaehler, &bruch1.nenner);
    scanf("%d/%d", &bruch2.zaehler, &bruch2.nenner);

    // Berechnung Produkts der Brüche
    produkt = multipliziere(bruch1, bruch2);

    // Berechnung Quotienten der Brüche
    quotient = dividiere(bruch1, bruch2);

    // Ausgabe des Produkts in der Form: "(Zähler1/Nenner1) * (Zähler2/Nenner2) = (ProduktZähler/ProduktNenner)"
    druckeBruch(bruch1); // Erster Bruch
    printf("*");         // Multiplikationszeichen
    druckeBruch(bruch2); // Zweiter Bruch
    printf("=");         // Gleichheitszeichen
    druckeBruch(produkt); // Ergebnis der Multiplikation
    printf("\n");        // Neue Zeile

    // Ausgabe des Quotienten in der Form: "(Zähler1/Nenner1) / (Zähler2/Nenner2) = (QuotientZähler/QuotientNenner)"
    druckeBruch(bruch1); // Erster Bruch
    printf("/");         // Divisionszeichen
    druckeBruch(bruch2); // Zweiter Bruch
    printf("=");         // Gleichheitszeichen
    druckeBruch(quotient); // Ergebnis der Division
    printf("\n");        // Neue Zeile

    return 0; // Programmende
}







