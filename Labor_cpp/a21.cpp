#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException : public std::exception { 
private:
string file_name;
int line_num; 
string ex_message;
string f_message; 
public:
  MyException(const char *f_name, int l_num, const string &msg = "x")
    : file_name{f_name}, line_num{l_num}, ex_message{msg} {
    f_message = "Fehler " + ex_message + " aufgetreten in Datei " + file_name + ", Zeile: " + to_string(line_num+39) + ".";   
  }

  virtual const char *what() const noexcept override {
    return f_message.c_str(); 
  }

  virtual ~MyException() noexcept = default; 
};

// Eigene Exceptionklasse abgeleitet
class ElefantMeetsMouse : public MyException {
public:
  ElefantMeetsMouse(const char *file_n, int line) 
    : MyException{file_n, line - 6, "'Elefant trifft auf Maus'"} {} 
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
    Animal *clone() const override {
    return new Elefant(*this); 
  }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal {
public:
  Tiger() : Animal() {}
    Animal *clone() const override {
    return new Tiger(*this); 
  }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal {
public:
  Mouse() : Animal() {}
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
          throw MyException(__FILE__, __LINE__, "'Zooname zu kurz'"); 
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
        for (const auto &a : animals) {
          a->print(true); 
        }
        

    }
};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER
    try {     

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
                cout << "Fehlerhafte Eingabe!" << endl; 
                return 1; 
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    catch (ElefantMeetsMouse &e)
    {
        cout << e.what() << endl;
    }
    catch (MyException& e) 
    {
        cout<< e.what()<<endl;
    }
    catch (const exception& e) 
    {
          cout << "Standardausnahme: " << e.what() << endl;
    } 
    catch (const string e) 
    {
          cout << "String Exception: " << e << endl; 
    } 
    catch (...) 
    {
        cerr << "Unbekannte Ausnahme aufgetreten." << endl; 
    }
    
    
    return 0;
}


