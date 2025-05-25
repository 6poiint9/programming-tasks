#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException : public std::exception { 
private:
short line_num; 
string file_name;
string ex_message;
string f_message; 
public:
  MyException(string f_name, short l_num, const string &msg = "x")
    : file_name{f_name}, line_num{l_num}, ex_message{msg} {
    f_message = "Fehler " + ex_message + " bei Datei " + file_name + " Zeile " + to_string(line_num);   
  }

  virtual const char *what() const noexcept override {
    return f_message.c_str(); 
  }

  virtual ~MyException() noexcept = default; 
};

// Eigene Exceptionklasse abgeleitet
class ElefantMeetsMouse : public MyException {
public:
  ElefantMeetsMouse(string file_n, short line) 
    : MyException{file_n, line, "Elefent trifft auf Maus"} {} 
};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    // Konstruktor
    Animal()
    {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };
    // virtuelle print-Funktion
    virtual void print(bool nl) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Animal *clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal {
public:
  Elefant() : Animal() {}
  
  void print(bool nl) const override {
    cout << "Name: "; 
    Animal::print(nl); 
  }

  Animal *clone() const override {
    return new Elefant(*this); 
  }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal {
public:
  Tiger() : Animal() {}
   
  void print(bool nl) const override {
    cout << "Name: "; 
    Animal::print(nl); 
  }

  Animal *clone() const override {
    return new Tiger(*this); 
  }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal {
public:
  Mouse() : Animal() {}
   
  void print(bool nl) const override {
    cout << "Name: "; 
    Animal::print(nl); 
  }

  Animal *clone() const override {
    return new Mouse(*this); 
  }
};

class Zoo
{
    string _name;
    vector<Animal *> animals;

public:
    Zoo() // construcor 
    {
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        if (_name.length() < 4) {
          throw MyException(__FILE__, __LINE__, "Name zu kurz"); 
        } 
        // Ansonsten, den 5. Buchstaben des Namens gross machen
        _name.at(4) = toupper(_name.at(4));
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal &animal)
    {
        // schauen ob bereits drinnen 
        bool has_elefant = false;
        bool has_mouse = false;

        for (auto a :animals) 
        {
          if (dynamic_cast<Elefant *>(a) != nullptr)
                has_elefant = true;
          if (dynamic_cast<Mouse *>(a) != nullptr)
                has_mouse = true;
        }
        
        // falls gemeinsam -> fehler 
        if ((has_elefant && dynamic_cast<Mouse const *>(&animal) != nullptr) ||
            (has_mouse && dynamic_cast<Elefant const *>(&animal) != nullptr))
        {
            throw ElefantMeetsMouse(__FILE__, __LINE__);
        }
        // sonst Tier hinzufuegen
        // HIER
        animals.push_back(animal.clone()); 

    }
    // Alle Zootiere ausgeben
    void print() const
    {
        for (const auto &animal : animals) {
          cout << animal << endl; 
        }
        

    }
};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER
    

        Zoo zoo;
        do
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                // HIER
               
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben
    catch (ElefantMeetsMouse &e)
    {
        cout << e.what() << endl;
    }
    // MyException auffangen und ausgeben
    // HIER
    

    // Alle anderen Standardausnahmen auffangen und ausgeben
    // HIER
    

    // Alle Strings auffangen und ausgeben
    // HIER
    

    // Alle anderen Ausnahmen auffangen
    catch (...) 
    {
        cerr << "unbekanntes exeption" << endl; 
    }
    
    
    return 0;
}


