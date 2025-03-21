#include <stdio.h>
#include <string.h>
// Kundenmanagementsystem

// Strukturdefinition für einen Kunden
struct Kunde {
    int kundennummer;       // Kundennummer
    char vorname[50];       
    char nachname[50];     
};

int main() {
    // struct Array für zwei Kunden
    struct Kunde kunden[2]; 

    // Kunde 1: Daten direkt festlegen
    kunden[0].kundennummer =   1;                 
    strcpy(kunden[0].vorname, "Hans");          
    strcpy(kunden[0].nachname, "Maurer");      

    // einlesen = ID vorname nachname
    scanf("%d %s %s", &kunden[1].kundennummer, kunden[1].vorname, kunden[1].nachname);

    // Ausgabe Kundendaten
    for (int i = 0; i < 2; i++) {
        printf("%d: %s %s\n", kunden[i].kundennummer, kunden[i].vorname, kunden[i].nachname);
    }

    return 0; // Programmende
}

