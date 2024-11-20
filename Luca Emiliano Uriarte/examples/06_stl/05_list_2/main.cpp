#include <iostream>
#include <list>
#include "complejos.h"
#include <math.h>

using namespace std;

template <class T> void vPrintLst(list<T> lst)
{
    typename list<T>::iterator ForIter;

    ForIter = lst.begin();                      // puntero al primer elemento
    cout << endl;
    while (ForIter != lst.end() )               // mientras no sea el último elemento
    {
        cout << *ForIter++ << endl;             // aumento el iterador
    }
    cout << "\n\n";
}

bool cmpfn (complejo &c1, complejo &c2)
{
    float fMod1, fMod2;

    fMod1 = sqrt(pow(c1.GetReal(), 2) + pow(c1.GetImag(), 2));
    fMod2 = sqrt(pow(c2.GetReal(), 2) + pow(c2.GetImag(), 2));

    return (fMod1 < fMod2);
}

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

    list<complejo> lst;            // crea una lista vacia

    lst.push_back(suma);           // agrego valores al final, crece sola
    lst.push_back(resta);
    lst.push_back(producto);
    lst.push_back(cociente);
    lst.push_front(c1);            // agrego valores al inicio, crece sola
    lst.push_front(c2);
    lst.push_front(c3);
    lst.push_front(c4);

    cout << "LISTA DE COMPLEJOS\n\nTamano inicial = " << lst.size();
    vPrintLst(lst);

    lst.sort(cmpfn);
    cout << "\nComplejos ordenados por modulo (menor a mayor): ";
    vPrintLst(lst);

    return 0;
}

