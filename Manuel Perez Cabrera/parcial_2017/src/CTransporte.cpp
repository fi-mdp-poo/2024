#include "CTransporte.h"

//CTransporte::CTransporte()
//{
//    //ctor
//}
CTransporte::CTransporte(string name, CColor col)
{
    Matricula = name ;
    Color = col;
}

CTransporte::~CTransporte()
{
    //dtor
}

void CTransporte::imprimir(ostream& os)
{
    os << "Transporte genérico";
}

ostream& operator<< (ostream& co, CTransporte &cmp)
{
    cmp.imprimir(co);
    return co;
}
