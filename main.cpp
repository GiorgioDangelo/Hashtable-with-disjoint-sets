#include <iostream>
#include "nodo_hashtable.h"
#include "Hashtable.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
string name;
int chiave;
int chiave1;
int indice;
int resp=5;
string value;
int key;



string nome_file;

cout<<"Inserisci il nome del file "<<endl;
cin>>nome_file;
Hashtable *asi=new Hashtable();


 ifstream infile;
 infile.open(nome_file,ios::in);
  if( !infile ){
    cerr << "file non trovato" << endl;
exit(0);
  }
cout<<"file aperto"<<endl;

char delimitatore=',';

/*LEGGERE LE TUPLE CON '<' '>'
char dem='>';
infile.ignore(1,'\n');//ignoro il primo elemento di ogni rigo

   while(( infile>>key >> delimitatore>>value>>dem) )
    {
    value.resize(value.size()-1);
    asi->inserisci_elemento(key,value);

    }
    infile>>key>>delimitatore>>value>>dem;
    value.resize(value.size()-1);
    asi->inserisci_elemento(key,value);
*/




      while(( infile>>key>>delimitatore>>value ))
    {

        asi->inserisci_elemento(key,value);

    }




bool ok = true;
  do {
   cout << "\n**** MENU ****\n\n";
    cout << " 1. MAKE_SET()\n";
    cout << " 2. UNION\n";
    cout << " 3. FIND_SET()\n";
    cout << " 4. STAMPA\n";
    cout << " 0. Exit\n";
    cout << ">_ ";
    cin >> resp;
    switch (resp) {
          case 0:
        ok = false;
        break;

      case 1:
       cout << "MAKE_SET() ";
       cout<<"INSERISCI LA CHIAVE E LA STRINGA DA INSERIRE :";
       cin>>chiave;
       cin >>name;
       asi->make_set(chiave,name);
        break;

      case 2:
       cout << "\n UNION\n";
        cout << "INSERISCI LE CHIAVI DA UNIRE :";
        cin>>chiave;
        cin>>chiave1;
        asi->Union(chiave,chiave1);
        break;

      case 3:
        cout << "FIND_SET() ";
        cout<<"INSERISCI IL NODO DI CUI VUOI TROVARE IL RAPPRESENTANTE :"<<endl;
        cin >> chiave;
        asi->find_set(chiave);
        break;

      case 4:
        cout<<"STAMPA L'INSIEME DISGIUNTO INSERENDO IL NUMERO :"<<endl;
        cin>>indice;
        asi->stampa_lista(indice);
        break;


      default:
        cout << "riprova ,puoi inserire il numero 0,1,2,3,4\n";
        continue;
    }
  } while (ok);


}
