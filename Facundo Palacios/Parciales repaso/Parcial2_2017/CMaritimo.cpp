#include "CMaritimo.h"

//CMaritimo::CMaritimo()
//{
//    //ctor
//}

CMaritimo::~CMaritimo()
{
    //dtor
}

CMaritimo::CMaritimo(string mat, string name, CColor col, int pas):
    CTransporte(mat, col)
{
    SetNombre(name);
    SetPasajeros(pas);
}

void CMaritimo::imprimir(ostream& co)
{
    co<<"Matricula:"<<this->GetMatricula()<<endl;
    co<<"Nombre:"<<this->GetNombre()<<endl;
    co<<"Cantidad pasajeros:"<<this->GetPasajeros()<<endl;
    co<<this->GetColor()<<endl;
}

ostream& operator<< (ostream& co, CMaritimo &cmp)
{
    cmp.imprimir(co);
    return co;
}
