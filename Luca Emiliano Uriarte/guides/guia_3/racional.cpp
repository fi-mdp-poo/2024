#include "racional.h"
#include <numeric> // Para std::gcd

CRacional::CRacional(int num, int den)
    : numerador(num)
    , denominador(den)
{
    if (den == 0)
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
    simplificar();
}

void
CRacional::simplificar()
{
    int gcd = std::gcd(numerador, denominador);
    numerador /= gcd;
    denominador /= gcd;
    if (denominador < 0)
    {
        numerador   = -numerador;
        denominador = -denominador;
    }
}

int
CRacional::get_numerador() const
{
    return numerador;
}

int
CRacional::get_denominador() const
{
    return denominador;
}

CRacional
CRacional::operator+(const CRacional &otro) const
{
    return CRacional(numerador * otro.denominador
                         + otro.numerador * denominador,
                     denominador * otro.denominador);
}

CRacional
CRacional::operator-(const CRacional &otro) const
{
    return CRacional(numerador * otro.denominador
                         - otro.numerador * denominador,
                     denominador * otro.denominador);
}

CRacional
CRacional::operator*(const CRacional &otro) const
{
    return CRacional(numerador * otro.numerador,
                     denominador * otro.denominador);
}

CRacional
CRacional::operator/(const CRacional &otro) const
{
    return CRacional(numerador * otro.denominador,
                     denominador * otro.numerador);
}

CRacional &
CRacional::operator+=(const CRacional &otro)
{
    numerador = numerador * otro.denominador + otro.numerador * denominador;
    denominador *= otro.denominador;
    simplificar();
    return *this;
}

bool
CRacional::operator==(const CRacional &otro) const
{
    return numerador == otro.numerador && denominador == otro.denominador;
}

bool
CRacional::operator<(const CRacional &otro) const
{
    return numerador * otro.denominador < otro.numerador * denominador;
}

bool
CRacional::operator>(const CRacional &otro) const
{
    return numerador * otro.denominador > otro.numerador * denominador;
}

CRacional &
CRacional::operator++()
{
    numerador += denominador;
    return *this;
}

CRacional
CRacional::operator++(int)
{
    CRacional temp = *this;
    numerador += denominador;
    return temp;
}

CRacional &
CRacional::operator--()
{
    numerador -= denominador;
    return *this;
}

CRacional
CRacional::operator--(int)
{
    CRacional temp = *this;
    numerador -= denominador;
    return temp;
}

CRacional
CRacional::operator-() const
{
    return CRacional(-numerador, denominador);
}

CRacional
operator+(double x, const CRacional &r)
{
    CRacional temp(static_cast<int>(x * r.denominador), r.denominador);
    return temp + r;
}

CRacional
operator+(const CRacional &r, double x)
{
    return x + r;
}

CRacional::operator double() const
{
    return static_cast<double>(numerador) / denominador;
}

std::ostream &
operator<<(std::ostream &out, const CRacional &r)
{
    out << r.numerador << '/' << r.denominador;
    return out;
}

std::istream &
operator>>(std::istream &in, CRacional &r)
{
    std::cout << "Numerador: ";
    in >> r.numerador;
    std::cout << "Denominador: ";
    in >> r.denominador;
    if (r.denominador == 0)
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
    r.simplificar();
    return in;
}