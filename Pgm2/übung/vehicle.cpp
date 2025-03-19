/*

*/


#include <iostream>

using namespace std;

class Vehicle {
  private:
   short anzahl; 
   bool motorisierung; 
  public:
  
   void set_method(short a = 0, bool m = true) {
      anzahl = a; 
      motorisierung = m;  
    }
   
   short get_anzahl() const {
    return anzahl;
   }
   
   bool get_motorisierung() const {
     return motorisierung; 
   }
   
   void print() {
     if (motorisierung) {
       cout << "Das Fahrzeug hat " << anzahl << " Achsen und ist motorisiert"; 
     }
     else {
      cout << "Das Fahrzeug hat " << anzahl << " Achsen und ist nicht motrisiert";    
     }
   }

};

tuple<short, bool>set_values(); 

int main() 
{
  Vehicle v1; 
  
  short anzahl;
  bool motorisierung;

  tie(anzahl, motorisierung) = set_values(); 
  
  // Set values 
  v1.set_method(anzahl, motorisierung); 
  
  // sachen mit print function ausgeben 
  v1.print(); 

  // sacen "manuell" mit getter-setter
  cout << "\nIch habe " << v1.get_anzahl() << " Achsen"; 

  return 0; 
}


tuple<short, bool>set_values() {
 short an;
 char antwort;
 bool mot; 
 
 cout << "Wie viele achsen hat das Fahrzeug? : ";
 cin >> an; 
 
 cout << "Ist das Fahrzeug motorisiert? (y / n) ? : ";
 cin >> antwort; 
  
 if (antwort == 'y') {
    mot = true; 
 }
 else if (antwort == 'n') {
    mot = false; 
  }
 else {
   cout << "Ungültige eingabe!"; 
 }

 return {an, mot}; 
}










