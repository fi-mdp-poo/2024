#include <iostream>
#include "prototipos.h"

using namespace std;

int main(){
    list<int> lista;
    int option=1, valor;
    while(option){
        cout<<"Choose an option: \n";
        cout<<"\t0.Exit the program \n\t1.Add a value to the list \n";
        cout<<"\t2.Remove a value of the list \n\t3. Print the list\n";
        cout<<"\t4. Print the inverted list\n";
        cin>>option;
        switch(option){
            case 0 : confirmarSalida(option); break;
            case 1 : {
                cout<<"Value to add: ";
                cin>>valor;
                agregarValor(lista, valor);
            } break;
            case 2 : {
                cout<<"Value to remove: ";
                cin>>valor;
                quitarValor(lista, valor);
            } break;
            case 3 : imprimirLista(lista); break;
            case 4 : imprimirListaInvertida(lista); break;
            default : cout<<"No option selected.\n";
        }
    }
    return 0;
}
