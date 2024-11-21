#include "cCliente.h"

cCliente::cCliente()
{
    //ctor
}

cCliente::~cCliente()
{
    //dtor
}


ostream&  operator<< (ostream& os, cCliente& actual)
{

    int a = actual.Getcuit();
    string  b = actual.Getnombre_cliente();
    os << "      Cliente: "<< b << ", "<<  a <<endl;

    return os;
}
