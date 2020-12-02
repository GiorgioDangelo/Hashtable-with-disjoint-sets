#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "nodo_hashtable.h"
#include <vector>
using namespace std;

class Hashtable
{
    public:

    void inserisci_elemento(int _key,string name);
    int divisione_k(int chiave);

    void make_set(int x,string name_1);
    void Union(int key1,int key2);
    void find_set(int num);
    void stampa_lista(int indice);
    bool cerca_chiave(int k);


    private:
        vector<nodo_hashtable*>A=vector<nodo_hashtable*>(702,nullptr);
        vector<int>size_lista=vector<int>(702,0);
};

#endif // HASHTABLE_H
