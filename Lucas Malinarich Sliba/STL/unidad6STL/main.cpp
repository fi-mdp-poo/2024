#include <iostream>
#include "prototipos.h"

using namespace std;

int main(){
    vector<int> arreglo;
    int option=1, valor;
    while(option){
        cout<<"Choose an option: \n";
        cout<<"\t0.Exit the program \n\t1.Add a value to the array \n";
        cout<<"\t2.Remove a value of the array \n\t3. Print the array\n";
        cout<<"\t4. Print the inverted array\n";
        cin>>option;
        switch(option){
            case 0 : confirmarSalida(option); break;
            case 1 : {
                cout<<"Value to add: ";
                cin>>valor;
                agregarValor(arreglo, valor);
            } break;
            case 2 : {
                cout<<"Value to remove: ";
                cin>>valor;
                quitarValor(arreglo, valor);
            } break;
            case 3 : imprimirVector(arreglo); break;
            case 4 : imprimirVectorInvertido(arreglo); break;
            default : cout<<"No option selected.\n";
        }
    }
    return 0;
}
