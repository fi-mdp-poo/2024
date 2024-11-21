#include "CMaritimo.h"

CMaritimo::CMaritimo()
{
    //ctor
}
CMaritimo::CMaritimo(string matri,string nombr,int col,int pasaj)
    :CTransporte(matri,col)
{
    //ctor
}

CMaritimo::~CMaritimo()
{
    //dtor
}
