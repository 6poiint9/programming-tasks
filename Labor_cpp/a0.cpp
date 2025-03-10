/*
Nutzer gibt zahlen ein 
-> entscheidet wie viele (max. 10)

-> einlesen und durchschnitt ausgeben
*/
#include <iostream>
#include <vector>

int main()
{
  // variablen deklarieren
  short anzahl; 
  short input;
  short summe = 0;  
  double durchschnitt; 
  // Fragen wie viele Zahlen eingegeben werden 
  std::cout << "Anzahl eingeben: ";
  std::cin >> anzahl;
  
  // Überprüfen ob anzahl zu groß
  if (anzahl > 10) {
    std::cout << "Anzahl darf maximal 10 sein";
    return 1; 
  }
  
  // damit man variable größe nutzen kann
  std::vector<short> zahlen(anzahl);
  // For-schleife um einzulesen 
  for (int i = 0; i < anzahl; i++) {
    std::cout << "Zahl eingeben: ";
    std::cin >> input; 
    zahlen[i] = input;
    //std::cout << "Zahl[" << elem << "]: " << input;  
    summe += input; 
  }
  // Ausgabe der eingeben Zahlen 
  for (short i = 0; i < anzahl; i++) {
    std::cout << "Zahl[" << i << "]: " << zahlen[i] << std::endl;  
  }
  // Nicht durch 0 teilen 
  if (anzahl == 0) {
    std::cout << "Anzahl ist 0!";
  }
  else {
    // Durchschnitt berechnen 
    durchschnitt = static_cast<double>(summe) / static_cast<double>(anzahl); 
  }
    // ausgabe von durchschnitt bis 4 nachkommastellen (gerundet) 
  std::cout << "Durchschnitt: " << durchschnitt; 
  
  return 0;
}

