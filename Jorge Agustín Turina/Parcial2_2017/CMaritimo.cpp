#include "CMaritimo.h"

CMaritimo::CMaritimo()
{
    //ctor
}

CMaritimo::~CMaritimo()
{
    //dtor
}

CMaritimo::CMaritimo(string mat, string name, int col, int pas):
    CTransporte(mat, col)
{
    SetNombre(name);
    SetPasajeros(pas);
}
