#include <iostream>
#include "prototipos.h"

using namespace std;

void confirmarSalida(int &option){
    cout<<"You are about to exit the program, to confirm the action press 0.\n";
    cin>>option;
}

void agregarValor(deque<int>& fila, int valor){
    auto itera = find(fila.begin(), fila.end(), valor);
    if(itera==fila.end()) fila.push_back(valor);
    else cout<<valor<<" already exist in the array.\n";
}

void quitarValor(vector<int>& fila, int valor){
    auto itera = find(fila.begin(), fila.end(), valor);
    if(itera!=fila.end()) fila.erase(itera);
    else cout<<valor<<" is not in the array.\n";
}

//void imprimirVector(const deque<int>& pila){
//    try{
//        if(arreglo.empty())
//            throw 0;
//        int longitud=arreglo.size();
//        for(int i=0; i<longitud; i++)
//            cout<<arreglo[i]<<" ";
//        cout<<endl;
//    }
//    catch (int){
//        cout<<"The array is empty.\n";
//    }
//}
//
//void imprimirVectorInvertido(const deque<int>& pila){
//    try{
//        if(arreglo.empty())
//        throw 0;
//        for(int i=arreglo.size()-1; i>=0; i--)
//            cout<<arreglo[i]<<" ";
//        cout<<endl;
//    }
//    catch (int){
//        cout<<"The array is empty.\n";
//    }
//}
