#include "CCirculo.h"

CCirculo::CCirculo()
{
    vSetRadio(44);
}

CCirculo::~CCirculo()
{
    //dtor
}

void CCirculo::vSetRadio(float r)
{
    Radio = r ;
}
float CCirculo::fGetRadio()
{
    return Radio;
}

double CCirculo::dCalcArea()
{
     CFigura::SetArea(3.14*fGetRadio());
    return 3.14*fGetRadio();
}

void CCirculo::SetValores(float v)
{
    vSetRadio(v);
}

void CCirculo::vImprimir(ostream& os)
{
     os <<"Soy circulo de radio =  "<< this->fGetRadio() <<" y area = " << this->dCalcArea()<<endl;
}
