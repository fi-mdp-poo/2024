#include "prototipos.h"

using namespace std;

//void confirmarSalida(int &option){
//    cout<<"You are about to exit the program, to confirm the action press 0.\n";
//    cin>>option;
//}

void agregarValor(vector<Persona>& arreglo, Persona valor){
    auto itera = find(arreglo.begin(), arreglo.end(), valor);
    if(itera==arreglo.end())
        arreglo.push_back(valor);
    else cout<<valor<<" already exist in the array.\n";
}

void quitarValor(vector<Persona>& arreglo, Persona valor){
    auto itera = find(arreglo.begin(), arreglo.end(), valor);
    if(itera!=arreglo.end())
        arreglo.erase(itera);
    else cout<<valor<<" is not in the array.\n";
}

void imprimirVector(const vector<Persona>& arreglo){
    if(arreglo.empty()){
        cout<<"The array is empty.\n";
        return;
    }
    int longitud=arreglo.size();
    for(int i=0; i<longitud; i++)
        cout<<arreglo[i]<<" ";
    cout<<endl;
}

void imprimirVectorInvertido(const vector<Persona>& arreglo){
    if(arreglo.empty()){
        cout<<"The array is empty.\n";
        return;
    }
    for(int i=arreglo.size()-1; i>=0; i--)
        cout<<arreglo[i]<<" ";
    cout<<endl;
}

vector<Persona> buscarPorApellido(const vector<Persona>arreglo, string Apellido){
    vector<Persona> resultado;
    int longitud=arreglo.size();
    for(int i=0; i<longitud; i++){
        if(arreglo.at(i).getApellido()==Apellido)
            resultado.push_back(arreglo.at(i));
    }
    return resultado;
}
