#include "CTransporte.h"

CTransporte::CTransporte()
{
    //ctor
}

CTransporte:: CTransporte(string mat, int col)
{
    SetMatricula(mat);
    SetColor(col);
}

CTransporte::~CTransporte()
{
    //dtor
}
