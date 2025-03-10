/*
Users can add lots of books 

Users can Delete Books 

View books (Display)
*/


#include<iostream>
#include <string>
//#include <memory>

using namespace std; 
// Class 
class Library {
 
 private:
  string *book; 
  string *author; 
  
 public: 

 // Constructor to allocate memory 
 Library(const string &bo = "default", const string &au = "default") : book{new string (bo)}, author{new string (au)} {} 
 
 // Copy constructor 
 Library(const Library &obj) 
  : book{new string {*(obj.book)}} 
  , author{new string {*(obj.author)}} {

 }  

 // Setter function to update Names 
 void set_names(const string &bo, const string &au) {
    *book = bo; 
    *author = au; 
  } 

 // function to add more books (or just use multiple objects)

 // display function to print out all books 
 void display () const {
    cout << "\nBooks in Library: \n"; 
    cout << *book << " by " << *author; 
  } 
 // Destructor to free memory 
 ~Library() {
    delete book; 
    delete author; 
  } 
}; 

tuple<string, string> set_values(); 

int main()
{ 
  char option;
  string bo, au;

  Library books; 

  do {
   cout << "Enter: \n"; 
   cout << "1 = Add a new book";
   cout << "2 = View books"; 
   cout << "3 = Remove a book"; 
   cout << "4 = Exit"; 
   cin >> option;
   
   switch (option) {
      case 1: { 
       cout << "choice: 1"; 
       tie(bo, au) = set_values();
       Library books(bo, au);
       break; 
      } 
      case 2: 
       cout << "choice: 2";
       books.display(); 
       break; 
      case 3: 
        
      case 4:
        cout << "choice: Exit";
        break; 
      default: 
        cout << "Invalid option";
    }
  
  }
  while (option != 4);
  
  return 0; 
}
  
tuple<string, string> set_values() {
  string bo, au; 
  // ask for input 
  cout << "Enter book Title: ";
  getline(cin, bo); 
  cout << "Enter author name: ";
  getline(cin, au); 
  
  return {bo, au}; 
}





