#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
using namespace std;
class LinkedList
{
    public:
    LinkedList();

     void inserisci_elemento_nella_lista(int key);
     void inserisci_stringa(string ins);
     int ritorna_chiave();
     string ritorna_stringa();
     void inserisci_next(LinkedList *next_1);
     LinkedList* ritorna_next();

    private:

       LinkedList *next;
       int key_info;
       string value;
};

#endif // LINKEDLIST_H
