#include "nodo_hashtable.h"

nodo_hashtable::nodo_hashtable()
{
    //ctor
}

void nodo_hashtable::inserisci_testa(LinkedList *testa)
{
head=testa;
}
LinkedList* nodo_hashtable::ritorna_testa()
{
return head;
}

void nodo_hashtable::inserisci_coda(LinkedList *tail)
{
coda=tail;
}

LinkedList* nodo_hashtable::ritorna_coda()
{
return coda;
}
