#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

template <class T> void vPrintLst(list<T> lst)
{
    typename list<T>::iterator ForIter;

    ForIter = lst.begin();                      // puntero al primer elemento
    cout << endl;
    while (ForIter != lst.end() )               // mientras no sea el último elemento
    {
        cout << *ForIter++ << " ";              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    list<int> lst;                              // crea una lista vacia
    list<int>::iterator ForIter,                // crea un iterador
                        stIter, enIter;         // iteradores de inicio y final
    unsigned int i;
    int valor;

    for(i=0; i<10; i++)
    {
        valor = rand();
        lst.push_back(valor);                    // agrega un elemento al final
        lst.push_front(valor);                   // agrega un elemento al principio
    }
    cout << "LISTA DE ENTEROS\n\nTamano inicial = " << lst.size();
    vPrintLst(lst);

    stIter = enIter = ForIter = lst.begin();     // iteradores desde el comienzo
    advance(stIter, 2);                          // tercer elemento
    advance(enIter, 12);                         // decimotercer elemento
    lst.erase(stIter, enIter);                   // elimina elementos
    cout << "\nSe eliminan los elementos desde el tercero al decimotercero:";
    vPrintLst(lst);

    lst.sort();
    cout << "\nSe ordenaron los elementos de la lista (menor a mayor): ";
    vPrintLst(lst);
    valor=lst.front();                           // otra forma de obtener el primer elemento
    cout << "Primer elemento: " << valor;
    valor=lst.back();                            // otra forma de obtener el último elemento
    cout << ", ultimo elemento: " << valor << endl;

    lst.reverse();
    cout << "\nSe ordenaron los elementos de la lista (mayor a menor): ";
    vPrintLst(lst);

    return 0;
}
