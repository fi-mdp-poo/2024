#include <iostream>
#include <list>
#include <algorithm>
//#include <math.h>

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

double reciproco(double i)                  // funcion unaria
{
    double v = 0;
    i ? v = 1.0/i : v;

    return v;                               // return reciproco
}

double cuadrado(int i, int j)               // funcion binaria
{
    return double(i*i + j*j);                     // return suma cuadratica
}

int main()
{
    list<double> vals;
    int loop;

    for(loop=0; loop<10; loop++)
    {
        vals.push_back(double(loop));
    }
    cout << "Contenido original de vals:\n";
    vPrintLst(vals);

    transform(vals.begin(), vals.end(), vals.begin(), reciproco);
    cout << "\nContenido transformado de vals:\n";
    vPrintLst(vals);

    list<int> val1, val2;
    list<double> result(10, 3.5);
    for(loop=0; loop<10; loop++)
    {
        val1.push_back(loop + 15);
        val2.push_back(loop * 3);
    }
    cout << "\n\nContenidos originales de val1, val2 y result:\n";
    vPrintLst(val1);
    vPrintLst(val2);
    vPrintLst(result);

    transform(val1.begin(), val1.end(), val2.begin(), result.begin(), cuadrado);
    cout << "\nContenido transformado:\n";
    vPrintLst(result);

    return 0;
}
