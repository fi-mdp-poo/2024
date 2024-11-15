#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>

using namespace std;

template <class ST, int cnt> class pila;
template <class ST, int cnt> ostream& operator<< (ostream&, pila<ST, cnt>&);

template <class ST=char, int cnt=10> class pila
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
        friend ostream& operator<< <> (ostream& co, pila<ST, cnt>&);
        ST operator[] (int);        // retorna la componente del indice seleccionado
};

#include "pila h_c.cxx"             // NO SE INCLUYE EL ARCHIVO EN EL PROJECT

#endif // PILA_H_INCLUDED
