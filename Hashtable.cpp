#include "Hashtable.h"
#include "LinkedList.h"
#include <vector>
#include <iostream>
using namespace std;

//*************************************************************************************
/*     METODO DIVISIONE        */
int Hashtable::divisione_k(int chiave){
if (chiave==0)         //NON SI PUO' FARE LA DIVISIONE PER 0
{
return 0;
}
else{
int resto_della_divisione=chiave%701;

return resto_della_divisione;

}
}

//*************************************************************************************
/*     INSERISCI ELEMENTO            */

void Hashtable::inserisci_elemento(int _key,string name)
{

int indice_posizione=divisione_k(_key);

//cout<<"Indice array :"<<indice_posizione<<endl;
size_lista[indice_posizione]++;   //Conta i numeri della lista
LinkedList *nuovo_link=new LinkedList();



nuovo_link->inserisci_elemento_nella_lista(_key);  //Assegno al nodo della lista la chiave
nuovo_link->inserisci_stringa(name);
cout<<"Nuovo nodo"<<endl;
cout<<"Indirizzo della lista creato:"<<nuovo_link<<" per il numero :"<<_key<<" con indice "<<indice_posizione<<endl; //Indirizzo della lista creato
 cout<<""<<endl;
nuovo_link->inserisci_next(nullptr);

if(A[indice_posizione]==nullptr){

nodo_hashtable *nuovo_hashtable=new nodo_hashtable();
//nuovo_hashtable->head=nuovo_link;
nuovo_hashtable->inserisci_testa(nuovo_link);
nuovo_hashtable->inserisci_coda(nuovo_link);
A[indice_posizione]=nuovo_hashtable;
 }

 else{

    LinkedList *temp;

    temp=A[indice_posizione]->ritorna_testa();

    while(temp->ritorna_next()!=nullptr)
    {

    temp=temp->ritorna_next();   //scorri la lista finchè non trovi il null

    }

   temp->inserisci_next(nuovo_link);   //inserisci il nuovo elemento nell'ultima posizione

A[indice_posizione]->inserisci_coda(temp->ritorna_next()); //Aggiorna coda


    }


}

//*************************************************************************************
/*     MAKE_SET()          */
void Hashtable::make_set(int numero,string name_1)
{
int indice_posizione=divisione_k(numero);



if(A[indice_posizione]==nullptr){
cout<<"Insieme disgiunto creato nell'indice di posizione "<<indice_posizione<<" del numero :"<<numero<<endl;
size_lista[indice_posizione]++;   //Conta i numeri della lista
LinkedList *nuovo_link=new LinkedList();

nuovo_link->inserisci_elemento_nella_lista(numero);  //Assegno al nodo della lista la chiave
nuovo_link->inserisci_stringa(name_1);
nuovo_link->inserisci_next(nullptr);
nodo_hashtable *nuovo_hashtable=new nodo_hashtable();
nuovo_hashtable->inserisci_testa(nuovo_link);
nuovo_hashtable->inserisci_coda(nuovo_link);
A[indice_posizione]=nuovo_hashtable;
 }
    else{
        cout<<"La cella e' gia' occupata"<<endl;
        int i=0;
        while(A[i]!=nullptr){
        i++;
        }
        cout<<"La prima cella vuota dove puoi inserire e' questa:"<<i<<endl;

    }

}

//*************************************************************************************
/*     CERCA CHIAVE              */
bool Hashtable::cerca_chiave(int k)
{
int indice_posizione=divisione_k(k);
bool ci_sono;
ci_sono=false;
  if (A[indice_posizione]==nullptr)
    {
    cout<<"La cella e' vuota,non punta a nessun insieme "<<endl;

    }
 else{
    LinkedList *temp;
    temp=A[indice_posizione]->ritorna_testa();
    while(temp!=nullptr)
{

    if (temp->ritorna_chiave()==k){
    ci_sono=true;
   // cout<<"Posizione della chiave all'interno dell'array : "<<indice_posizione<<" Chiave trovata :"<<temp->ritorna_chiave()<<endl;
    break;}
    temp=temp->ritorna_next();
}

 }
return ci_sono;
}
//*************************************************************************************
/*        UNION                */
void Hashtable::Union(int key1,int key2)
{
    int indice_1=divisione_k(key1);
    int indice_2=divisione_k(key2);

    bool cerca_1=cerca_chiave(key1);
    bool cerca_2=cerca_chiave(key2);
if (A[indice_1]==A[indice_2] || cerca_1==false || cerca_2==false ||A[indice_1]->ritorna_testa()==A[indice_2]->ritorna_testa() )
{
    cout<<"Una delle due liste e' vuota ,oppure stai cercando di unire la stessa lista ,oppure la chiave nn esiste"<<endl;
}
else{

    //cout<<"Size lista 1:"<<size_lista[indice_1]<<endl;
    //cout<<"Size lista 2:"<<size_lista[indice_2]<<endl;

if (size_lista[indice_1]==size_lista[indice_2] ||size_lista[indice_1]>size_lista[indice_2]){ //Se le liste sono uguali allora una vale l'altra,se la lista 1 è maggiore della 2 allora la lista 2 si deve accodare alla 1
cout<<"Union riuscita"<<endl;

size_lista[indice_1]=size_lista[indice_1]+size_lista[indice_2];
size_lista[indice_2]=size_lista[indice_1];
//cout<<"nuovo size :"<<size_lista[indice_1]<<endl;
LinkedList *temp,*temp1;  //Puntatori alle due liste
temp=A[indice_1]->ritorna_coda(); //Nel caso in cui la prima lista sia maggiore,allora prendo la coda della prima lista
temp1=A[indice_2]->ritorna_testa(); //Prendo la testa della seconda lista

while(temp1!=nullptr){      //scorro tutti gli elementi della seconda lista,e per ogni elemento presente lo inserisco nella coda della prima lista

        temp->inserisci_next(temp1);
        temp1=temp1->ritorna_next();
        temp=temp->ritorna_next();  //aggiorno la coda

}

A[indice_1]->inserisci_coda(temp);
//cout<<"leggi il numero coda :"<<A[indice_1]->ritorna_testa()->ritorna_chiave()<<endl;
A[indice_2]->inserisci_testa(A[indice_1]->ritorna_testa()); //faccio puntare la testa della lista alla lista dove è stata unita
A[indice_2]->inserisci_coda(A[indice_1]->ritorna_coda());
//cout<<"Nuova testa :"<<A[indice_2]->ritorna_testa()<<endl;
//cout<<"Nuova coda :"<<A[indice_1]->ritorna_coda()<<endl;

}
else{
        cout<<"Union riuscita"<<endl;
size_lista[indice_2]=size_lista[indice_2]+size_lista[indice_1];
size_lista[indice_1]=size_lista[indice_2];
//cout<<"nuovo size :"<<size_lista[indice_2]<<endl;
    LinkedList *temp,*temp1; //Puntatori alle due liste
    temp=A[indice_1]->ritorna_testa();
    temp1=A[indice_2]->ritorna_coda();
    while(temp!=nullptr)
    {

        temp1->inserisci_next(temp);
        temp=temp->ritorna_next();
        temp1=temp1->ritorna_next();
    }

A[indice_2]->inserisci_coda(temp1); //aggiorno la coda della lista
A[indice_1]->inserisci_testa(A[indice_2]->ritorna_testa()); //faccio puntare la testa della lista alla lista dove è stata unita
A[indice_1]->inserisci_coda(A[indice_2]->ritorna_coda());
}

}

}



//*************************************************************************************
/*     STAMPA LISTA             */
void Hashtable::stampa_lista(int indice_1)
{
    int indice=divisione_k(indice_1);

   //cout<<"leggi valore dell'indice :"<<A[indice]<<endl;
    if (A[indice]==nullptr)
    {
    cout<<"La lista e' vuota "<<endl;
    }
 else{
   LinkedList *temp;
   temp=A[indice]->ritorna_testa();
    while(temp!=nullptr)
{
   cout<<"Valori della lista con  Chiave :" <<temp->ritorna_chiave()<<" Stringa :"<<temp->ritorna_stringa()<<endl;

   temp=temp->ritorna_next();

}


 }
}


//*************************************************************************************
/*     FIND SET           */

void Hashtable::find_set(int k)     //ritorno il rappresentante di una lista
{
int indice_posizione=divisione_k(k);   //restituisco l'indice con il metodo della divisione

bool ok=cerca_chiave(k);             //Verifico se la chiave esiste all'interno della lista


if(ok==true)
{
cout<<"Il rappresentante di  "<<k<<" e' :"<<A[indice_posizione]->ritorna_testa()->ritorna_chiave();
}
else{
cout<<"Non esiste "<<k<<" all'interno di nessuna lista"<<endl;
}

}
