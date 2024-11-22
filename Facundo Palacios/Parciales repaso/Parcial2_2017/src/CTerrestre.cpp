#include "CTerrestre.h"

//CTerrestre::CTerrestre()
//{
//
//}

CTerrestre::CTerrestre(string mat, string marc, CColor col, int rue, float vel) :
    CTransporte(mat, col)
{
    SetMarca(marc);
    SetRuedas(rue);
    SetVelocidad(vel);
}

CTerrestre::~CTerrestre()
{
    //dtor
}

void CTerrestre::imprimir(ostream& co)
{
     co<<"Matricula:"<<this->GetMatricula()<<endl;
    co<<"Marca:"<<this->GetMarca()<<endl;
    co<<"Velocidad maxima:"<<this->GetVelocidad()<<endl;
    co<<"Cantidad Ruedas:"<<this->GetRuedas()<<endl;
    co<<this->GetColor()<<endl;
}

ostream& operator<< (ostream& co, CTerrestre &cmp)
{
    cmp.imprimir(co);
    return co;
}
