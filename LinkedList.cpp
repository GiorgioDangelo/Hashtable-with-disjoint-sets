#include "LinkedList.h"

LinkedList::LinkedList()
{
    //ctor
}
int LinkedList::ritorna_chiave()
{
return key_info;
}
void LinkedList::inserisci_elemento_nella_lista(int key)
{
key_info=key;
}

void LinkedList::inserisci_stringa(string ins)
{
value=ins;
}

string LinkedList::ritorna_stringa()
{
return value;
}
void LinkedList::inserisci_next(LinkedList *next_1)
{
    next=next_1;
}

LinkedList* LinkedList::ritorna_next()
{
return next;
}
