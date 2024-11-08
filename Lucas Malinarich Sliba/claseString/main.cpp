#include <iostream>
#include "claseString.h"

using namespace std;

int main(){
    myString *string1= new myString();
    *string1="Hola mundo.";
    imprimirString(*string1);
    string1->copiarString("Valor copiado.");
    imprimirString(*string1);
    string1->concatenarString("\nValor concatenado.");
    imprimirString(*string1);
    *string1+="\nOperador += sobrecargado";
    imprimirString(*string1);
    delete string1;
    return 0;
}
