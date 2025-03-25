#include <iostream>

using namespace std;

class List {
 private:
  int _data; 
  List *p_next; 
 
 public: 
  
  List() {
    cout << "IntArrayElement erzeugt.\n"; 
  }

  int get_data() const {
    return _data; 
  }
  
  List *get_next() {
    return p_next; 
  }

  void set_data(int data) {
    _data = data; 
  }

  void set_next(List* next) {
    p_next = next; 
  }

  ~List() {
    cout << "IntArrayElement zerstört\n."; 
   }
};



class Dynamic {
  
 private:
  List *root; 
  

 public:
  
 Dynamic() : root{nullptr} {}
 
 ~Dynamic() {
    
    delete p_next; 
  }

  void push_back(int data) {
   List *new_element = new List(); 
   new_element->set_data(data);
   new_element->set_next(nullptr); 
   
   if (root == nullptr) { root = new_element;} 
   }

  int size() {
    int i = 0; 
    List *tmp = root; 
    
    while (tmp != nullptr) {
      tmp = tmp->get_next();
      i++; 
    }
   return i; 
  }

  int at(int index) {
    List *tmp = root;

    int i = 0; 

    while(index != i) {
      tmp = tmp->get_next();
      i++; 
    }
    return tmp->get_data(); 
  } 
 
 


};

int main() 
{
  


  return 0;
}









