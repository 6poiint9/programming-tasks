/*
-  kommentiere minimale Anzahl von Funktionsdefinitionen aus

- Kommentieren Sie keine Zeile im Hauptprogramm aus

- Nennen Sie die Funktionen, die im Hauptprogramm aufgerufen werden
*/


#include <iostream>
using namespace std;

// Einzelne char werden umgewandelt zu 

int function(int i_1)
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}
/*void function(int i_1)
{
    cout << "Funktion  2: i_1=" << i_1 << endl;
}

// eigentlich EGAL -> nur eine unkommentiert da return-type keine signatur ist  
// -> diese function nicht kommentiert,da ein daten typ char in main übergeben wird  
char function(int i_1)
{
    cout << "Funktion  3: i_1=" << i_1 << endl;
    return 'a';
}

int function(int &i_1)
{
    cout << "Funktion  4: i_1=" << i_1 << endl;
    return 1;
}
*/
// ---------------------------------------------------


int function(int i_1, int i_2) // 2_1 
{
    cout << "Funktion  5: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}
int function(char c_1, int i_1) // 3_6 , 2_2  
{
    cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
    return 1;
}
/*int function(int i_1, int i_2 = 0)
{
    cout << "Funktion  7: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}
*/
// -------------------------------------------------- 
int function(double d_1, int i_1, char c_1 = 'a') // 2
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}
// 2_3 (default argument), 1 , 3 (implizit konvertiert), 4 (default value )
int function(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}
/*int function(double d_1, double d_2 = 1.1, char c_1) 
{
    cout << "Funktion 10: d_1=" << d_1 << " d_2=" << d_2 << " c_1=" << c_1 << endl;
    return 1;
}
*/
int function(char c_1, char c_2, int i_1 = 2, char c_3 = 'c') // 5 (default argument)
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}
int main(int argc, char* argv[]) 
{
    int i = 1;
    char c = 'a';
    function(1);
    function(c);
    function(i);
    c = function('a');
    c = 'a';

    function(1, 2); // 2_1 
    function(c, i); // 2_2
    function(1.0, 2.0); // 2_3 
    
    function(1.0, 2.0, 1); // 1
    function(1.0, 1, 'a'); // 2
    function(1.0, 1); // 3
    function(1.0, static_cast<double>(i)); // 4
    function(c, c, i); // 5 
    function(c, i); // 3_6  
    return 0;
}


