#include "CMaritimo.h"


CMaritimo::CMaritimo(string matri,string nombr,CColor col,int pasaj)
    :CTransporte(matri,col)
{
    //ctor
}

CMaritimo::~CMaritimo()
{
    //dtor
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
