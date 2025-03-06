#include <iostream>
#include <string>


using namespace std; 

class Library {
 // private variables
 private:
  string title;
  string author; 
  string price; 

 public:
  // let user set values 
  Library(const string &t, const string &a) : title{t}, author{a}, price{"15.99"} {}
  
  // Setter function 
  void newprice(const string &p) {
   price = p; 
  }
  
  
  void display() const {
    cout << "\nBook Added:\n"; 
    cout << "Title: " << title << endl; 
    cout << "Author: " << author << endl; 
    cout << "Price: " << price << "$" << endl; 
  }

  void display_price() const {
    cout << "\nNew price: " << price << "$" << endl; 
  }
}; 

// function prototypes 
void update_price(bool update, Library &b2); 

int main() 
{
  // get user input 
  // get book name
  string book_title, author_name; 
  
  cout << "Enter book title: ";
  getline(cin, book_title);  
   
  cout << "Enter author name: "; 
  getline(cin, author_name);  

  // padss to obj constructor
  Library b1(book_title, author_name);
  b1.display(); 
  
  // update price 
  bool update = false;
   
  cout << "\nWanna update the price? (y=1 , n=0): "; 
  cin >> update; 

  update_price(update, b1); 

 return 0; 
};


void update_price(bool update, Library &b2) {

string price_updated; 

 if (update == true) {
    cout << "Enter new price: ";
    cin >> price_updated; 
    
    b2.newprice(price_updated);
    b2.display_price(); 
  }
 else {
   cout << "Price stays the same"; 
  }
}





