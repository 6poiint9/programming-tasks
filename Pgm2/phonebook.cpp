#include <iostream>
//#include <memory>
#include <string>

using namespace std;

// Struct prototype
struct contact {
  string name;
  string num; 
  struct contact *next;
};

// function prototypes
contact *createContact(string name, string num); 
void addContact(contact **head, contact *newcontact);
void searchContact(contact *head, string name); 
void deleteContact(contact **head, string name);
void print(contact *head); 
void freePhonebook(contact **head);

// sorting functions 
contact *mergeSort(contact *head);
contact *getMiddle(contact *head);
contact *merge(contact *left, contact *right); 

int main()
{
  // initialize head 
  contact *head = nullptr; 
  
  // create some default contacts 
  addContact(&head, createContact("Joe", "+1-212-456-6969"));
  addContact(&head, createContact("Eli", "+1-342-456-7893"));
  addContact(&head, createContact("Lilly", "+1-234-456-3890"));
  addContact(&head, createContact("Anna", "+1-239-456-5090")); 
  // let the user add one contact 
  string name, num; 
  
  cout << "Enter name: \n"; 
  cin >> name; 

  cout << "Enter number; \n";
  cin >> num; 

  addContact(&head, createContact(name, num));
  
  // print the list Once before sorting
  cout << "OG List:\n"; 
  print(head); 
  
  // sort the list 
   head = mergeSort(head); 

  // print the list after sorting
  cout << "After sorting:\n";
  print(head); 

  // Ask user if he wants to search a contact 
  char decide;  
  cout << "Do you want to search for a contact? (y, n): \n"; 
  cin >> decide; 

  if (decide == 'y'){
    cout << "Enter name to search: \n";
    cin >> name; 
    searchContact(head, name); 
  }
  else if (decide == 'n') {
    cout << "ok\n";
  }
  else {
   cout << "could not read input properly!\n"; 
  }


  // delete a contact 
  string delname; 
  cout << "Enter a contact to delete: \n";
  cin >> delname; 

  deleteContact(&head, delname); 
  
  // print list after deletion 
  cout << "After deleting a contact:\n"; 
  print(head); 
  
  // free the list 
  freePhonebook(&head); 

  return 0; 
}


contact *createContact(string name, string num) {
  // allocate memory 
  contact *newcontact = new contact; 
  // check if allocation successfull
  if (newcontact == nullptr) {
    cout << "Allocation failed!\n";
    return nullptr;
  }

  // assign values to the members 
  newcontact->name = name; 
  newcontact->num = num;

  // point node to next node 
  newcontact->next = nullptr; 

  return newcontact;
} 

void addContact(contact **head, contact *newcontact) { 
  // check if list empty
  if (*head == nullptr) {
    *head = newcontact; // new head  
  } 
  else {
   contact *temp = *head; // new temp node created for traversal from head 
   // traverse list 
   while (temp->next != nullptr) {
      temp = temp->next; // go to next node 
    }
    temp->next = newcontact; // insert node at end 
  }
}





void deleteContact(contact **head, string name) {
  // if list empty return 
  if (*head == nullptr) {
    return; 
  }
  // check if head is to be deleted 
  if (*head != nullptr && (*head)->name == name) {
    contact *temp = *head; // create a temp node to store head 
    *head = (*head)->next; // make 2. node head new node 
    delete(temp); // delete/free head
    temp = nullptr; // avoid dangling 
  }
  // else traverse list
  contact *current = *head; // create node for traversing 
  while (current != nullptr && current->next != NULL) {
    if (current->next->name == name) { 
      contact *temp = current->next; // if save node in temp 
      current->next = current->next->next; // re-link the list 
      delete(temp); // delete the node 
      temp = nullptr; // avoid dangling 
    }
    else { 
      current = current->next; // if not found go to next node  
    }
  }
}

void searchContact(contact *head, string name) {
  // check if list empty 
  if (head == nullptr) {
    return; // Quit if empty 
  }
    contact *current = head; // start traversing from head
    bool found = false; // check if number found 

    while (current != nullptr) {
      if (current->name == name) {
        cout << "Name: " << current->name << endl; // if found print info 
        cout << "Number: " << current->num << endl; 
        found = true; // true if found
        break; // stop loop if found  
      }
      current = current->next; // move to next node 
    }
    if (!found) {
      cout << "Contact not found :(\n"; // if not found
    }
}

void print(contact *head) {
  // check if list empty
  if (head == nullptr) {
    return;
  }
  // start from head  
  contact *current = head;
  // traverse list 
  while (current != nullptr) {
    cout << "Name: " << current->name << endl; // print name 
    cout << "Number: " << current->num << endl; // print number 

    current = current->next; // move to next node 
  }
  cout << "End reached!\n"; // print NULL if end reached 
}

void freePhonebook(contact **head) {
  // check if list empty 
  if (*head == nullptr) {
    return; 
  }
  else {
    contact *current = *head; // start at head
    contact *nextcontact= nullptr; // save next node before freeing 

    while (current != nullptr) {
      current->next = nextcontact; // save next node
      delete(current); // delete current node 
      current = nextcontact; // move to next node 
    }
  }
  *head = nullptr; // avoid dangling
}

contact *getMiddle(contact *head) {
  // Empty list case 
  if (!head || !head->next) return head; 
  
  // initialize pointers to head 
  contact *slow = head; 
  contact *fast = head->next; // head->next 

  // Loop through list and find middle
  while (fast && fast->next) {
    // fast moves 2x 
    fast = fast->next->next; 
    slow = slow->next;
  }
  return slow; 

}

contact *merge(contact *left, contact *right) {
 // Base case 
 if (!left) return right; 
 if (!right) return left; 

 contact *result = nullptr; 

 // Compare first-letter and sort
 if (left->name[0] < right->name[0]) {
   // If left letter is smaller
   result = left; // sort first 
   result->next = merge(left->next, right); // compare next element form next to right  
 } else {
   // if right letter is smaller
   result = right; // sort in first
   result->next = merge(left, right->next); 
 }
 return result; 
} 

contact *mergeSort(contact *head) {
  // recurive
  // base case:
  if (!head || !head->next) return head; 
 
  // call getmiddle function => get middle node
  contact *middlecontact = getMiddle(head); 
  contact *secondhalf = middlecontact->next; // create second list
  middlecontact->next = nullptr; 

  // create lists recursively
  contact *left = mergeSort(head); 
  contact *right = mergeSort(secondhalf); 
  
  // sort it using merge function
  return merge(left, right); 
  
} 

















