#include "CRectangulo.h"

CRectangulo::CRectangulo()
{
    //ctor
}

CRectangulo::~CRectangulo()
{
    //dtor
}


void CRectangulo::vSetBase(float b)
{
    Base = b;
}

void CRectangulo::vSetAltura(float a)
{
    Altura = a;
}

float CRectangulo::fGetBase()
{
    return Base;
}
//void CRectangulo::SetValores(float, float)
//{
//
//}
float CRectangulo::fGetAltura()
{
    return Altura;
}

double CRectangulo::dCalcArea()
{

    CFigura::SetArea(Base*Altura);

    return Base*Altura;
}

void CRectangulo::vImprimir(ostream& os)
{
    os <<"Soy un rectangulo de base =  "<< this->fGetBase() <<", altura =  "<<this->fGetAltura()<<" y area "<<this->dCalcArea() << endl;

}
