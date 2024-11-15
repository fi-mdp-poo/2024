#ifndef PILA3_H_INCLUDED
#define PILA3_H_INCLUDED

#include <iostream>
#include "persona.h"

using namespace std;

template <class ST, const int cnt> class pila;
template <class ST, const int cnt> ostream& operator<< (ostream&, pila<ST, cnt>&);

template <class ST, const int cnt> class pila
{
    private:
        ST *st;                     // memoria reservada para el stack
        int tos;                    // indice del top-of-stack
        int tam;                    // tamaño del stack
    public:
        pila();                     // constructor
        ~pila();                    // destructor
        void push(ST);              // agrega un objeto al stack
        ST pop();                   // obtiene un objeto desde el stack
        friend ostream& operator<< <> (ostream& , pila<ST, cnt>& );
        ST operator[] (int);        // retorna la componente del indice seleccionado
};

#endif // PILA3_H_INCLUDED
//undefined reference to `std::ostream& operator<< <char, 5>(std::ostream&, pila<char, 5>&)'|
