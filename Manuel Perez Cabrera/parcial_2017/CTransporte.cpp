#include "CTransporte.h"

CTransporte::CTransporte(string , int )
{
    //ctor
}

CTransporte::~CTransporte()
{
    //dtor
}


string CTransporte::GetMatricula(){
    return matricula;

}

void CTransporte::SetMatricula(string name){
    matricula = name;
}
