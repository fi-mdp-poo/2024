#include "CRacional.h"
#include <iostream>

using namespace std;

int CRacional::gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

CRacional::CRacional(int num, int den): numerador(num), denominador(den)
{
    if (den==0)
    {
        throw invalid_argument("El denominador no puede ser cero");
    }
    reducir();
}

CRacional::CRacional(const CRacional& r)
{
    setNumerador(r.numerador);
    setDenominador(r.denominador);
}

CRacional::CRacional(double v)
{
    numerador=static_cast<int>(v*10000);
    denominador=10000;
    reducir();
}

CRacional::~CRacional(){};


void CRacional::reducir()
{
    int g=gcd(numerador, denominador);
    numerador/=g;
    denominador/=g;
}

void CRacional::setNumerador(int a)
{
    numerador=a;
}

void CRacional::setDenominador(int a)
{
    denominador=a;
}

int CRacional::getNumerador() const
{
    return numerador;
}

int CRacional::getDenominador() const
{
    return denominador;
}

istream& operator>>(istream& is, CRacional& r)
{
    int i;
    cout << "Ingrese el numerador: "<<endl;
    is >> i;
    r.setNumerador(i);
    cout << endl << "Ingrese el denominador: "<<endl;
    is >> i;
    r.setDenominador(i);
    if(r.denominador==0)
    {
        cout<<endl;
        cout<< "BURRO, denominador=1";
        r.setDenominador(1);
    }
    return is;
}

CRacional CRacional::operator+(const CRacional& r)
{
    CRacional a;
    a.numerador= numerador*r.getDenominador() + r.getNumerador()*denominador;
    a.denominador=denominador*r.getDenominador();
    a.reducir();
    return a;
}

CRacional& CRacional::operator=(const CRacional& r)
{
    if(this==&r) return *this;

    setNumerador(r.getNumerador());
    setDenominador(r.getDenominador());
    return *this;
}

CRacional& CRacional::operator+=(const CRacional& r)
{
    *this=*this+r;
    return *this;
}

ostream& operator<<(ostream& os, CRacional& r)
{
   os << r.getNumerador() << " / " << r.getDenominador() << endl;
   return os;
}
CRacional CRacional::operator-()
{
    CRacional a;
    a.numerador=-numerador;
    a.denominador=denominador;
    return a;
}

CRacional CRacional::operator-(const CRacional& r)
{
    CRacional a;
    a.numerador= numerador*r.getDenominador() - r.getNumerador()*denominador;
    a.denominador=denominador*r.getDenominador();
    a.reducir();
    return a;
}

CRacional CRacional::operator*(const CRacional& r)
{
    CRacional a;
    a.numerador= numerador*r.getNumerador();
    a.denominador=denominador*r.getDenominador();
    a.reducir();
    return a;
}

CRacional CRacional::operator/(const CRacional& r)
{
    CRacional a;
    a.numerador= numerador*r.getDenominador();
    a.denominador=denominador*r.getNumerador();
    a.reducir();
    return a;
}

CRacional& CRacional::operator++()
{
    numerador+=denominador;
    reducir();
    return *this;
}

CRacional CRacional::operator++(int)
{
    CRacional temp=*this;
    ++(*this);
    return temp;
}

CRacional& CRacional::operator--()
{
    numerador-=denominador;
    reducir();
    return *this;
}

CRacional CRacional::operator--(int)
{
    CRacional temp=*this;
    --(*this);
    return temp;
}

bool CRacional::operator==(const CRacional& r)
{
    return numerador==r.getNumerador() && denominador==r.getDenominador();
}

bool CRacional::operator<(const CRacional& r)
{
    return numerador*r.getDenominador() < r.getNumerador()*denominador;
}

bool CRacional::operator>(const CRacional& r)
{
    return numerador*r.getDenominador() > r.getNumerador()*denominador;
}

bool CRacional::operator!()
{
    return numerador==0;
}

CRacional operator+(double lhs, const CRacional& rhs)
{
    CRacional lhsracional(lhs);
    return lhsracional + rhs;
}


CRacional::operator double() const
{
    return static_cast<double>(numerador) / denominador;
}
