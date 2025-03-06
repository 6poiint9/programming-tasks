#include <iostream>
#include <string>

using namespace std; 

// Prototype for a Book 
class Book {
 public: // ASK safe ? -> private when using vectors ?  
  string title;
  string author; 
  // constructor to create 
  Book(const string &t = "", const string &a = "") : title{t}, author{a} {}
  
  // Display function
  void display() const {
   cout << " " << title << " by " << author << endl; 
  }
}; 

// => Class to store multiple books dynamically
class Library {
 private: 
  Book **books; // ASK  
  int capacity; 
  int count; 
  
 public: 
  Library(int cap = 10) : capacity{cap}, count{0} {
   books = new Book *[capacity]; 
  }
  
  // Function to add books
  void add(const string &title, const string &author) {
    if (count < capacity) {
     books[count++] = new Book(title, author); 
     cout << "Book added successfully!\n"; 
    }
    else {
     cout << "Library full!\n"; 
    }
  } 
  
  // Display function 
  void displayBooks() const {
   // check if list emply 
   if (count == 0) {
    cout << "No books in the Library!\n"; 
    return; 
   }
   else {
    cout << "\n Books in Library:\n"; 
    for (int i = 0; i < count; i++) {
     cout << i + 1 << ". "; 
     books[i]->display(); 
    }
   }
  }

   // Function to remove Books
   void remove(int index) {
    // check if lib empty 
    if (count == 0) {
     cout << "No books to remove, Library is empty!\n";
     return; 
    }
    
    if (index < 1 || index > count) {
     cout << "Invalid book number!\n"; 
     return; 
    } 
    else {
     delete books[index - 1]; // ASK // free memory 
     // Re-order books
     for (int i = index -1; i < count - 1; i++) {
      books[i] = books[i + 1]; // shift books 
     }
     count--; // -1 book
     cout << "Book removed!\n"; 
    }
   }
   
   // Destructor to free memory 
   ~Library() {
     for (int i = 0; i < count; i++) {
      delete books[i]; 
    }
    delete[] books; 
  }
};  

// Function get book details 
tuple<string, string> set_values(); 

int main() 
{
  // Initialize objetct
  Library lib; 
  int choice; 

  do {
   cout << "\n1. Add a new book\n2. View books\n3. Remove a book\n4. Exit\n";
   cout << "Choice: ";
   cin >> choice;

   switch (choice) {
    case 1: {
     string title, author;
      tie(title, author) = set_values();
      lib.add(title, author);
      break;
    }
    case 2: 
     lib.displayBooks(); 
     break;
    case 3: { 
     int index; 
     cout << "Enter Book number to delete:";
     cin >> index;
     lib.remove(index); 
    }
    case 4: 
     cout << "Exiting...\n"; 
     break;
    default:
     cout << "Invalid option!\n"; 
   }
  } while (choice != 4); 


 return 0; 
}

tuple<string, string> set_values() {
 string title, author; 
    cin.ignore(); // Ignore leftover newline
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    return {title, author};
}





