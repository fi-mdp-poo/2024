#include <iostream>
#include "prototipos.h"

using namespace std;

void confirmarSalida(int &option){
    cout<<"You are about to exit the program, to confirm the action press 0.\n";
    cin>>option;
}

void agregarValor(list<int>& lista, int valor){
    auto itera = find(lista.begin(), lista.end(), valor);
    if(itera==lista.end()) lista.push_back(valor);
    else cout<<valor<<" already exist in the list.\n";
}

void quitarValor(list<int>& lista,int valor){
    auto itera=find(lista.begin(), lista.end(), valor);
    if(itera!=lista.end()) lista.erase(itera);
    else cout<<valor<<" is not in the list.\n";
}

void imprimirLista(const list<int>& lista){
    if(lista.empty()) {
        cout<<"The list is empty.\n";
        return;
    }
    for(auto it=lista.begin(); it!=lista.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}

void imprimirListaInvertida(const list<int>& lista){
    if(lista.empty()) {
        cout<<"The list is empty.\n";
        return;
    }
    for(auto it=lista.rbegin(); it!=lista.rend(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}
