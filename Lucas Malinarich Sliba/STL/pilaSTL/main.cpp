#include <iostream>
#include "clasePersona.h"
#include <stack>

//Por consigna de la guía los datos serán borrados después de mostrarlos en pantalla
void imprimirPila(stack<Persona>& pila);

int main(){
    stack<Persona>pila;
    //Creo objetos para almacenar
    Persona persona1("Pedro", "Gomez", 1);
    Persona persona2("Ana", "Gomez", 2);
    Persona persona3("Jorge", "Lopez", 3);
    Persona persona4("Marcos", "Fernandez", 4);
    Persona persona5("Martina", "Hernandez", 5);
    Persona persona6("Mercedez", "Giovanni", 6);
    Persona persona7("Juan", "Lopez", 7);
    Persona persona8("Mateo", "Hernandez", 8);
    Persona persona9("Luz", "Gomez", 9);
    //Almaceno los objetos
    pila.push(persona1);
    pila.push(persona2);
    pila.push(persona3);
    pila.push(persona4);
    pila.push(persona5);
    pila.push(persona6);
    pila.push(persona7);
    pila.push(persona8);
    pila.push(persona9);

    imprimirPila(pila);
    cout<<pila.empty()<<endl;
    return 0;
}

void imprimirPila(stack<Persona>& pila){
    while(!pila.empty()){
        cout<<pila.top()<<endl;
        pila.pop();
    }
}
