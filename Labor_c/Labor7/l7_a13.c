#include <stdio.h>

int main()
{
  // array mit 4 elementen
  int arr[4];
  // summe mit = 0 initialisieren
  int summe = 0;
  float durchschnitt; 
  // einlesen
  for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
  // schleife => summe und durchschnitt berechnen
  for (int i = 0; i < 4; i++) {
   // die eingaben auf addieren
   summe += arr[i];
  } 
  // durchschnittberechnen
  durchschnitt = (float)summe / 4.0;
  // Ausgabe
  printf("Summe: %d\nDurchschnitt: %.6f\n", summe, durchschnitt);

  return 0;
}
