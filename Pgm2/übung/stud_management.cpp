#include <iostream>
#include <string>
#include <tuple>

using namespace std; 

class System {
  // initialize variables as private 
  private:
   string name; 
   string age;
   string gpa; 

  public:
   // constuctor to add a student
   System(const string &n, const string &a, const string &g) : name{n}, age{a}, gpa{g} {}
    
   // setter function 
   void update_gpa(const string &g) {
    gpa = g; 
  }
   // getter function
   string get_gpa() const {
    return gpa; 
  }

   // other functions 
   void display() const {
    cout << "\nStudent Details:\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl; 
    cout << "GPA: " << gpa << endl; 
   }
    
}; 
// Function Prototypes
tuple<string, string, string> getValues();
void ask_gpa(System &init_gpa); 

int main()
{
 string s_name, s_age, s_gpa; 
 
 tie(s_name, s_age, s_gpa) = getValues();

 System init(s_name, s_age, s_gpa);
  
 init.display(); 
 // pass object
 ask_gpa(init); 

  return 0; 
}

tuple<string, string, string> getValues() {
  string n, a, g; 
  
  cout << "Enter name: ";
  getline(cin, n); 

  cout << "Enter age: ";
  cin >> a; 

  cout << "Enter GPA: ";
  cin >> g; 

  return {n, a, g}; 
}

void ask_gpa(System &init_gpa) {

 // ask if wanting to change GPA 
  char answer; 
  string new_gpa; 

  cout << "\nWant to change your GPA ? (y / n): "; 
  cin >> answer; 
  
  if (answer == 'y' ) {
    cout << "\nEnter new GPA: "; 
    cin >> new_gpa; 
    // pass by value 
    init_gpa.update_gpa(new_gpa);
    // display
    cout << "Updated GPA: " << init_gpa.get_gpa(); 
  }
  else {
    return; 
  }
}



