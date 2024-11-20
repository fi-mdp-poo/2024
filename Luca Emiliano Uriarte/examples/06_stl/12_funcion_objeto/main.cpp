#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include <vector>
#include <math.h>
#include "complejos.h"

using namespace std;

template <class T> void vPrintVec(vector<T> v)
{
    typename vector<T>::iterator ForIter;

    ForIter = v.begin();                        // puntero al primer elemento
    cout << endl;
    while (ForIter != v.end() )                 // mientras no sea el último elemento
    {
        cout << *ForIter++ << "    ";           // aumento el iterador
    }
    cout << "\n\n";
}

template <class T> void vPrintLst(list<T> v)
{
    typename list<T>::iterator ForIter;

    ForIter = v.begin();                        // puntero al primer elemento
    cout << endl;
    while (ForIter != v.end() )                 // mientras no sea el último elemento
    {
        cout << *ForIter++ << "    ";           // aumento el iterador
    }
    cout << "\n\n";
}

class reciproca : unary_function<int, double>
{
    public:
        result_type operator()(argument_type i)
        {
            return (result_type) 1.0/i;         // return reciprocal
        }
};

class modulo : unary_function<complejo, double>
{
    public:
        result_type operator()(argument_type comp)
        {
            return (result_type) sqrt(comp.GetReal()*comp.GetReal()
                                      + comp.GetImag()*comp.GetImag());
        }
};

class promedio : binary_function<int, char, double>
{
    public:
        result_type operator()(first_argument_type factor, second_argument_type c)
        {
            return (result_type) ( (factor + double(c))/2.0 );
        }
};

int main()
{
    list<int> iVals;
    list<double> dVals(10);
    int loop;

    for(loop=1; loop<11; loop++)
    {
        iVals.push_back(loop);
    }
    cout << "Contenido original de iVals:\n";
    vPrintLst(iVals);

    transform(iVals.begin(), iVals.end(), dVals.begin(), reciproca());
    cout << "Valores reciprocos con mi funcion unaria reciproca:\n";
    vPrintLst(dVals);

    transform(iVals.begin(), iVals.end(), dVals.begin(), negate<int>());
    cout << "Valores negados con stl negate<int>():\n";
    vPrintLst(dVals);

    complejo c1(1.1, 2.2),        // se crean e inicializan dos complejos (constructor general)
             c2(3.3, 4.4),        // se crea un complejo con el constructor por defecto
             c3(7.5),             // se crea un complejo con el valor por defecto (0.0) del 2do. argumento
             suma = c1 + c2,      // se crea un complejo a partir del resultado (constructor de copia)
             producto = c1 * c3;  // inicializados por el constructor por defecto

    vector<complejo> cVec(3);     // crea un vector de 3 complejos
    vector<double> dVec(5);       // crea un vector de 5 doubles

    cVec[0] = c1;                 // asigna valores consecutivos
    cVec[1] = c2;
    cVec[2] = c3;
    cVec.push_back(suma);         // agrego valores al final, crece solo
    cVec.push_back(producto);
    cout << "\n\n\nVector de " << cVec.size() << " complejos:" << endl;
    vPrintVec(cVec);

    transform(cVec.begin(), cVec.end(), dVec.begin(), modulo());
    cout << "Calculo de los modulos con mi funcion unaria:\n";
    vPrintVec(dVec);

    vector<int> iFact;
    vector<char> cFact;
    for(loop=0; loop<5; loop++)
    {
        iFact.push_back(27-2*loop);
        cFact.push_back(loop + 'A');
    }
    transform(iFact.begin(), iFact.end(), cFact.begin(), dVec.begin(), promedio());
    cout << "\n\n\nCalculo del promedio entre int y char con mi funcion binaria:\n";
    vPrintVec(iFact);
    vPrintVec(cFact);
    vPrintVec(dVec);
    cout << endl << endl;

    return 0;
}
