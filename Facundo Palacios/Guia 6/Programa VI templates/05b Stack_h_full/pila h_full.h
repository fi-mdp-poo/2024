#ifndef PILA_H_FULL_H_INCLUDED
#define PILA_H_FULL_H_INCLUDED

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

template <class ST, int cnt> ST pila<ST, cnt>::operator[](int indice)
{
    if(indice && indice<tam)
    {
        return st[indice];
    }
    else
    {
        cout << "Indice = " << indice << " excede el maximo ("
             << tam << "). Se retorna el ultimo valor = ";
        return st[tam-1];
    }
}

template <class ST, int t> ostream& operator<< (ostream& co, pila<ST, t>& obj)
{
    cout << endl << endl;
    for(int i=0; i<obj.tos; i++)
    {
       cout << "Valor [" << i << "] = " << obj.st[i] << endl;
    }
    cout << "Tamano = " << obj.tam << "\n\n";

    return co;
}

template <class ST, int cnt> pila<ST, cnt>::pila()
{
    tos = 0;
    tam = cnt;
    st = new ST[tam];
}

template <class ST, int cnt> pila<ST, cnt>::~pila()
{
    delete [] st;
}

template <class ST, int cnt> void pila<ST, cnt>::push(ST obj)
{
    if(tos == tam)
    {
        cout << "La pila esta completa.\n";
        return;
    }
    st[tos] = obj;
    tos++;
}

template <class ST, int cnt> ST pila<ST, cnt>::pop()
{
    if( !tos )
    {
        cout << "La pila esta vacia.\n\n";
        return 0;                       // return null
    }
    tos--;

    return st[tos];
}

#endif // PILA_H_FULL_H_INCLUDED
