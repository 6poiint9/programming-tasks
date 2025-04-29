#include<iostream>
using namespace std;

class Date {
private: 
	int _day, _month, _year;

public:
  // konstruktor für startdatum 
	Date(int d = 0, int m = 0, int y = 0) : _day{d}, _month{m}, _year{y} {} 
  
  // operator overloading für '+'
	Date operator+(int days) {
    // Objekt Auf aktuells datum zeigen (begin_date) 
    Date newdate = *this; 
    // von tage
    newdate._day += days;
    
    // überfluss an tagen zu monat übertragen
    short add_months = newdate._day / 30; 
    newdate._day = newdate._day % 30; 
    // zu Monate
    newdate._month += add_months; 
    
    short add_years = newdate._month / 12; 
    newdate._month = newdate._month % 12; 
    // zu Jahre 
    newdate._year += add_years; 

    return newdate; 
  }

	friend ostream & operator<<(ostream &out, const Date &date) {
    // ausgabe der daten  
    out << date._day << "." << date._month << "." << date._year; 
    return out; 
  }
  
};


int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}

