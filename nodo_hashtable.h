#ifndef NODO_HASHTABLE_H
#define NODO_HASHTABLE_H
#include "LinkedList.h"
using namespace std;

class nodo_hashtable
{
    public:
    nodo_hashtable();

    void inserisci_testa(LinkedList *testa);
    void inserisci_coda(LinkedList *tail);
    LinkedList *ritorna_testa();
    LinkedList *ritorna_coda();
    private:
    LinkedList *head;  //Puntatore alla testa della lista
    LinkedList *coda;  //Puntatore alla coda della lista
};

#endif // NODO_HASHTABLE_H
