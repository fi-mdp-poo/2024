#include <iostream>
#include "prototipos.h"

using namespace std;

int main(){
    deque<int> fila;
    int option=1, valor;
    while(option){
        cout<<"Choose an option: \n";
        cout<<"\t0.Exit the program \n\t1.Add a value to the deque \n";
        cout<<"\t2.Remove a value of the deque \n\t3.Print the deque\n";
        cout<<"\t4.Print the inverted array\n";
        cin>>option;
        switch(option){
            case 0 : confirmarSalida(option); break;
            case 1 : {
                cout<<"Value to add: ";
                cin>>valor;
                agregarValor(fila, valor);
            } break;
            case 2 : {
                cout<<"Value to remove: ";
                cin>>valor;
                quitarValor(fila, valor);
            } break;
//            case 3 : imprimirFila(fila); break;
//            case 4 : imprimirFilaInvertida(fila); break;
            default : cout<<"No option selected.\n";
        }
    }
    return 0;
}
