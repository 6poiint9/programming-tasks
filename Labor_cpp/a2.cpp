//#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement* p_next;
};

// head-pointer global initialisiert
ListElement* p_root = nullptr;

void add_new_head_element(int id)
{   
    // Speicher für neues element bereitstellen 
    ListElement* p_new_element = new ListElement();
    // werte initialisieren 
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    // newnode becomes new head  
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    // Neuen node erstellen
    ListElement *p_new_element = new ListElement(); 
    p_new_element->id = id; 
    // pointer mit nullptr initialisieren
    p_new_element->p_next = nullptr;

    // Schauen ob Liste leer -> neuer kopf 
    if (p_root == nullptr) {
      p_root = p_new_element; 
    }
    else {   // Sonst liste traversieren und am ende hinzufügen
     // temp pointer 
     ListElement *temp = p_root; // beginnt von vorne  
     while (temp->p_next != nullptr) {
     // zum nächsten pointer gehen wenn nicht am ende 
     temp = temp->p_next; 
     }
     temp->p_next = p_new_element; // tempnode zuordnen  
    }  
}

void delete_element(int id)
{   
    // listen Element löschen nach id 

    ListElement *p_tmp = p_root; // tmp zu traversieren 
    ListElement *p_predecessor = nullptr;
    
    // traversieren bis id gefunden wurde oder bis ende erreicht wurde 
    while (p_tmp != nullptr && p_tmp->id != id)
    {   
        p_predecessor = p_tmp; // point current node 
        p_tmp = p_tmp->p_next; // point next node 
    }
    if (p_tmp != nullptr) // falls id gefunden wurde (vor listenende)
    {
        if (p_tmp == p_root) 
        {   
            p_root = p_tmp->p_next; // listenkopf aktualisieren falls kopf
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next; // liste neu ordnen 
        }
    }
    delete p_tmp;
}

void print_list()
{
    ListElement *p_temp = p_root; // auf kopf zeigen um von beginn zu starten 
    // schauen ob liste leer 
    if (p_root == nullptr) return; 
    // Sonst liste traversieren und member ausgeben
    while (p_temp != nullptr) {
     cout << p_temp->id << endl; 
     p_temp = p_temp->p_next;  
    }
} 

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};


