/*
Schere - Stein - Papier 

-> objekt wird von "Spieler" eingelesen 
-> computer nimmt random objekt 

=> objekte werden verglichen und es wird einen Sieger geben 
*/

#include <iostream>
#include <ctime>
#include <pthread.h>
#include <string>

using namespace std;
// Wählbare Objekte 
enum class Object 
{
  ROCK, // 0
  SCISSORS, // 1
  PAPER // 2
};

// Mögliche spielausgänge 
enum class Result 
{
  PLAYER_ONE_WINS,
  PLAYER_TWO_WINS,
  DRAW
}; 

// Spieler struktur 
struct Player {
  std::string name;
  Object choice; // Variable vom typ enum für zugriff auf objekte  
};

// Funktion prototypen 
std::string insert_name(); // Spielername eingeben 
Object determine_choice(std::string choice); // Je nach 
std::string get_name(Object object); // gewähltes Objekt als string zurückgeben
Object choose(); // Wahl des spielers einlesen 
void print_choice(Player player); // Spielername und gewähltes Objekt ausgeben
Result determine_result(Player player_1, Player player_2); // Objekte vergleichen und ergebniss zurückgeben 
void print_result(Player player_1, Player player_2); // Ergebniss ausgeben -> gewonnen / unentschieden 

int main()
{
  // Struct-variablen initialisieren 
  Player player_1, player_2;
  
  // Namen initialisieren
  player_1.name = "Computer";
  player_2.name = insert_name();
  
  // Computer wählt ein objekt
  player_1.choice = determine_choice(player_2.name);
  cout << "Der Computer hat seine Wahl getroffen." << endl;
  
  // Spieler wählt ein objekt
  player_2.choice = choose();
  
  // Gewähltes objekt ausgeben  
  print_choice(player_1);
  print_choice(player_2);
  
  // Ergebniss Ausgeben  
  print_result(player_1, player_2);

  return 0;
}



string insert_name() {
  string name;
 cout << "Name des Spielers: "; 
 getline(cin, name);

 // Name zurückgeben
 return name;
} 

Object determine_choice(string choice) {
    
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Wie funktioniert die funktion rand?
        // Warum wird hier modulo 3 verwendet?

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

string get_name(Object object) {
  string chosen_object;
  switch (object) {
    case Object::ROCK:
      chosen_object = "Stein";
      break;
    case Object::SCISSORS:
      chosen_object = "Schere";
      break;
    case Object::PAPER:
      chosen_object = "Papier";
      break;
  }
  return chosen_object;
}

Object choose() {
  char wahl; 
  Object object;
  //cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";

  // Schleife 
  do {
   cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
   cin >> wahl; 
   // switch-statement um eingabe zuzuordnen
   switch (wahl) {
      case '1':
        object = Object::ROCK;
        break;
      case '2':
        object = Object::SCISSORS;
        break;
      case '3':
        object = Object::PAPER;
        break;
    }
  }
  while(wahl < '1' || wahl > '3');

  return object;
}

void print_choice(Player player) {
  // Funktion aufrufen um objekt als string zu bekommen  
  string choice = get_name(player.choice);
  cout << player.name << " hat das Objekt " << choice << " gewählt\n";  
}

Result determine_result(Player player_1, Player player_2) {
  Result result;
  // Condition für ALLE fälle bei der Computer/Spieler gewinnt sonst unentschieden
  if ( 
     (static_cast<int>(player_1.choice) == 0 && static_cast<int>(player_2.choice) == 1) || 
     (static_cast<int>(player_1.choice) == 1 && static_cast<int>(player_2.choice) == 2) ||
     (static_cast<int>(player_1.choice) == 2 && static_cast<int>(player_2.choice) == 0)
     )
     {
      result = Result::PLAYER_ONE_WINS; 
  }
  else if (
     (static_cast<int>(player_2.choice) == 0 && static_cast<int>(player_1.choice) == 1) || 
     (static_cast<int>(player_2.choice) == 1 && static_cast<int>(player_1.choice) == 2) ||
     (static_cast<int>(player_2.choice) == 2 && static_cast<int>(player_1.choice) == 0)
  )   
  {
     result = Result::PLAYER_TWO_WINS;
  }
  else {
    result = Result::DRAW; 
  }
  return result;
}
 
void print_result(Player player_1, Player player_2) {
  // Ergebnis initialisieren
  Result result = determine_result(player_1, player_2);

  // Ausgabe basierend auf ergebniss 
  switch (result) {
    case Result::PLAYER_ONE_WINS:
      cout << "Computer hat gewonnen";
      break;
    case Result::PLAYER_TWO_WINS:
      cout << player_2.name << " hat gewonnen.";
      break;
    case Result::DRAW:
      cout << "Unentschieden";
      break;
  }
}

