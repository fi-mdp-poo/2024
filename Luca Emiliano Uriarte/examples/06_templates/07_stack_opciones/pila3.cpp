#include "pila3.h"

template <class ST, const int cnt> ST pila<ST, cnt>::operator[](int indice)
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

template <class ST, const int cnt> pila<ST, cnt>::pila()
{
    tos = 0;
    tam = cnt;
    st = new ST[tam];
}

template <class ST, const int cnt> pila<ST, cnt>::~pila()
{
    delete [] st;
}

template <class ST, const int cnt> void pila<ST, cnt>::push(ST obj)
{
    if(tos == tam)
    {
        cout << "La pila esta completa.\n";
        return;
    }
    st[tos] = obj;
    tos++;
}

template <class ST, const int cnt> ST pila<ST, cnt>::pop()
{
    if( !tos )
    {
        cout << "La pila esta vacia.\n\n";
        return st[0];                       // return null
    }
    tos--;

    return st[tos];
}

template class pila <char, 5>;
template class pila <double, 10>;
template class pila <persona, 2>;

/*****
//  produce error porque todavía no se especificaron los templates --> poner en el main()
template <class ST, int t> ostream& operator<< (ostream& co, pila<ST, t>& obj)
{
    return co;
}
****/



