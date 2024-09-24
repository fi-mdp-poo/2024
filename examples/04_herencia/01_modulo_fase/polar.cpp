#include "polar.h"
#include <math.h>

polar::polar()
{
    fModulo = 0.0;
    fFase = 0.0;
}

polar::polar(complejo& comp): complejo(comp)
{
    fModulo = CalModulo(comp);
    fFase = CalFase(comp);
 //   m_real = comp.GetReal();
 //   m_imag = comp.GetImag();
}

polar::polar(float r, float i, bool modo) : complejo(r, i)
{
    if(modo)
    {
        fModulo = r;
        fFase = i;
        ToRect();
    }
    else
    {
        fModulo = CalModulo(*this);
        fFase = CalFase(*this);
    }
}

float polar::GetModulo()
{
    return fModulo;
}

void polar::SetModulo(float valor)
{
    fModulo = valor;
}

float polar::GetFase()
{
    return fFase;
}

void polar::SetFase(float valor)
{
    fFase = valor;
}

float polar::CalModulo(complejo& valor)
{
    fModulo = sqrt(pow(valor.GetReal(), 2) + pow(valor.GetImag(), 2));

    return fModulo;
}

float polar::CalFase(complejo& valor)
{
    fFase = atan2(valor.GetImag(), valor.GetReal()) * 180.0 / 3.1415927;

    return fFase;
}

void polar::ToRect()
{
    m_real = fModulo*cos(fFase*3.1415927/180.0);
    m_imag = fModulo*sin(fFase*3.1415927/180.0);
}

void polar::ToPolar()
{
    fModulo = CalModulo(*this);
    fFase = CalFase(*this);
}

polar polar::operator+ (polar& sumando)
{
    polar aux;
    aux.m_real = m_real + sumando.m_real;
    aux.m_imag = m_imag + sumando.m_imag;
    aux.ToPolar();

    return aux;
}
/*
polar polar::operator+= (polar& sumando)
{
    m_real+= sumando.m_real;
    m_imag+= sumando.m_imag;
    this->ToPolar();

    return (*this);
}
*/
polar operator* (double factor, polar& pol)
{
    polar aux(pol);

    aux.fModulo*= factor;
    aux.ToRect();

    return aux;
}

polar polar::operator*= (double factor)
{
    fModulo*= factor;
    ToRect();

    return (*this);
}

double operator* (polar& pol1, polar& pol2)
{
    return (pol1.fModulo * pol2.fModulo * cos((pol1.fFase - pol2.fFase)*3.1415927/180.0) );
}

ostream& operator<< (ostream& co, const polar &pol)
{

    co << pol.fModulo << "/";
    co << pol.fFase << " grados";

    return co;
}


