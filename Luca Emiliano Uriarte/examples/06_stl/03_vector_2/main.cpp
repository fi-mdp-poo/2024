#include <iostream>
#include <vector>
#include "complejos.h"

using namespace std;

int main()
{
    complejo c1(1.1, 2.2),        // se crean e inicializan dos complejos (constructor general)
             c2(3.3, 4.4),        // se crea un complejo con el constructor por defecto
             c3,
             c4(7.5),             // se crea un complejo con el valor por defecto (0.0) del 2do. argumento
             suma = c1 + c2,      // se crea un complejo a partir del resultado (constructor de copia)
             resta, producto, cociente;   // inicializados por el constructor por defecto

    c3.SetReal(5.0);              // se fijan los valores de las partes real e imaginaria de c3
    c3.SetImag(2.0);

    resta = c1 - c2;
    producto = c1 * c2;
    cociente = c1 / c2;

    // se imprimen los numeros complejos con el operador << sobrecargado
    cout << "Primeros cuatro valores = " << c1 << ", " << c2 << ", " << c3 << ", " << c4 << endl << endl;
    cout << "Suma:     " << suma << endl << endl;
    cout << "Resta:    " << resta << endl << endl;
    cout << "Producto: " << producto << endl << endl;
    cout << "Cociente: " << cociente << endl << endl;

    vector<complejo> cVec(4);       // crea un vector de 4 complejos
    unsigned int i;

    cVec[0] = c1;                   // asigna valores consecutivos
    cVec[1] = c2;
    cVec[2] = c3;
    cVec[3] = c4;
    cout << "\nVECTOR DE COMPLEJOS\n\nTamano original = " << cVec.size() << endl;

    cVec.push_back(suma);           // agrego valores al final, crece solo
    cVec.push_back(resta);
    cVec.push_back(producto);
    cVec.push_back(cociente);
    cout << "\nTamano aumentado = " << cVec.size() << endl << endl;

    for(i=0; i<cVec.size(); i++)
    {
        cout << "Valor en la posicion " << i << " = " << cVec[i] << endl;
    }

    vector<complejo>::iterator ForIter;
    ForIter = cVec.begin();             // iterador para complejos
    ForIter+= 2;                        // tercer elemento
    cVec.erase(ForIter, ForIter+2);     // elimino componentes 3ra y 4ta
    cVec.push_back(c1);                 // agrego valores al final, crece solo
    cout << "\nSe eliminaron las componentes 3ra, y 4ta y se agrego la 1ra al final\n";
    for(i=0; i<cVec.size(); i++)
    {
        cout << "Valor en la posicion " << i << " = " << cVec[i] << endl;
    }
    cout << endl << endl;

    return 0;
}
