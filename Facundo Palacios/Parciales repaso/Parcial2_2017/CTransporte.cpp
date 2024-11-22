#include "CTransporte.h"

//CTransporte::CTransporte()
//{
//    //ctor
//}

CTransporte:: CTransporte(string mat, CColor col)
{
    SetMatricula(mat);
    SetColor(col);
}

CTransporte::~CTransporte()
{
    //dtor
}

ostream& operator<< (ostream& co, CTransporte &cmp)
{
    cmp.imprimir(co);
    return co;
}
