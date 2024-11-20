#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stdlib.h>

using namespace std;

// Prueba el inner template. Quiero una sola funcion para imprimir un vector, lista, etc.
// Fuente: http://stackoverflow.com/questions/20373466/nested-c-template-parameters-for-functions
template <class Tipo, class Alloc, template <class Tipo, class Alloc> class Cont>
    void vPrintCont(Cont<Tipo, Alloc> &con)
{
    typename Cont<Tipo, Alloc>::iterator ForIter;

    ForIter = con.begin();                      // puntero al primer elemento
    cout << endl;
    while (ForIter != con.end() )               // mientras no sea el último elemento
    {
        cout << *ForIter++ << " ";              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    unsigned int i;
    int valor;

    list<int> lst;                              // crea una lista vacia
    for(i=0; i<10; i++)
    {
        valor = rand();
        lst.push_back(valor);                    // agrega un elemento al final
    }
    cout << "LISTA DE ENTEROS\n\nTamano inicial = " << lst.size();
    vPrintCont(lst);
    lst.sort();
    cout << "\nSe ordenaron los elementos de la lista (menor a mayor): ";
    vPrintCont(lst);

    vector<char> cVec(10);
    cout << "\n\nVECTOR DE CARACTERES\n\nTamaño original = " << cVec.size() << endl;
    for(i=0; i<10; i++)
    {
        cVec[i] = i + 'a';                      // asigna valores consecutivos
    }
    vPrintCont(cVec);

    float pi = 3.1415927;

    deque<float> fDque;
    cout << "\n\nDEQUE DE FLOTANTES\n\nTamaño original = " << cVec.size() << endl;
    for(i=10; i; i--)
    {
        fDque.push_front(i*pi);                    // agrega un elemento al principio
    }
    vPrintCont(fDque);

    return 0;
}
