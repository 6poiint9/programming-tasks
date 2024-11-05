#include <stdio.h>
//#include <math.h>

// Function to calculate the weekday
int weekday(int tag, int monat, int jahr) {
    int w, century, year;
    // Adjust month and year if the month is January or February
    if (monat < 3) {
        monat += 12;
        jahr -= 1;
    }
    
    // Calculate century and year within century
    century = jahr / 100;
    year = jahr % 100;

    // Apply Zeller's Congruence formula
    w = (tag + (13 * (monat + 1)) / 5 + year + (year / 4) + (century / 4) - 2 * century) % 7;

    // Adjust result to get correct weekday (1=Monday, ..., 7=Sunday)
    return (w + 5) % 7 + 1;
}

int main() {
  printf("%d", weekday(29, 04, 2021));
  return 0;
}


