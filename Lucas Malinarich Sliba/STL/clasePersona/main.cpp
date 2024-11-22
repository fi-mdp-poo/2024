#include "prototipos.h"

using namespace std;

int main(){
    vector<Persona> arreglo;
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
    agregarValor(arreglo, persona1);
    agregarValor(arreglo, persona2);
    agregarValor(arreglo, persona3);
    agregarValor(arreglo, persona4);
    agregarValor(arreglo, persona5);
    agregarValor(arreglo, persona6);
    agregarValor(arreglo, persona7);
    agregarValor(arreglo, persona8);
    agregarValor(arreglo, persona9);
    //Imprimo el valor original
    imprimirVector(arreglo);
    //Busco todas las personas con X apellido
    vector<Persona> aux;
    aux=buscarPorApellido(arreglo, "Lopez");
    //Imprimo el resultado
    imprimirVector(aux);
    return 0;
}
