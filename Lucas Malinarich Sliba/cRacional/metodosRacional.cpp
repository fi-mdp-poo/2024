#include <iostream>
#include "claseRacional.h"

using namespace std;

void CRacional::setNumerador(int num){
    numerador=num;
}

void CRacional::setDenominador(int den){
    if(den==0){
        denominador=1;
        std::cout<<"El denominador no puede ser cero, para evitar errores denominador=1.\n";
    }
    else denominador=den;
}

int CRacional::getNumerador()const{ return numerador; }
int CRacional::getDenominador()const{ return denominador; }

CRacional::CRacional(int num, int den){
    setNumerador(num);
    setDenominador(den);
}

CRacional::~CRacional(){  }

istream& operator>>(istream& cin, CRacional &referencia){
    int numero;
    cout<<"Ingrese numerador: ";
    cin>>numero;
    referencia.setNumerador(numero);
    cout<<"\nIngrese denominador: ";
    cin>>numero;
    referencia.setDenominador(numero);
    return cin;
}

ostream& operator<<(ostream& Cout, const CRacional &referencia){
    cout<<referencia.getNumerador()<<"/"<<referencia.getDenominador()<<endl;
    return Cout;
}

CRacional CRacional::operator+(const CRacional &valor){
    CRacional suma;
    suma.setNumerador(getNumerador()*valor.getDenominador()+valor.getNumerador()*getDenominador());
    suma.setDenominador(getDenominador()*valor.getDenominador());
    return suma;
}

CRacional operator+(const double numReal, const CRacional &valor){
    CRacional resultado=valor; //falta calcular como corresponde el equivalente racional del double
    return resultado;
}

CRacional CRacional::operator-(const CRacional &valor){
    CRacional resta;
    resta.setNumerador(getNumerador()*valor.getDenominador()-valor.getNumerador()*getDenominador());
    resta.setDenominador(getDenominador()*valor.getDenominador());
    return resta;
}

CRacional CRacional::operator-(){
    CRacional copia=*this;
    setNumerador(getNumerador()*(-1));
    return copia;
}

CRacional CRacional::operator*(const CRacional &valor){
    CRacional producto;
    producto.setNumerador(getNumerador()*valor.getNumerador());
    producto.setDenominador(getDenominador()*valor.getDenominador());
    return producto;
}

CRacional CRacional::operator/(const CRacional &valor){
    CRacional resultado;
    resultado.setNumerador(getNumerador()*valor.getDenominador());
    resultado.setDenominador(getDenominador()*valor.getNumerador());
    return resultado;
}

CRacional& CRacional::operator=(const CRacional &valor){
    if(this!=&valor){
        setNumerador(valor.getNumerador());
        setDenominador(valor.getDenominador());
    }
    return *this;
}

CRacional& CRacional::operator+=(const CRacional &valor){
    *this=*this+valor;
    return *this;
}

CRacional& CRacional::operator-=(const CRacional &valor){
    *this=*this-valor;
    return *this;
}

CRacional& CRacional::operator*=(const CRacional &valor){
    *this=(*this)*valor;
    return *this;
}

CRacional& CRacional::operator/=(const CRacional &valor){
    *this=*this/valor;
    return *this;
}

bool CRacional::operator==(const CRacional &valor){
    int entero1, entero2;
    entero1=getNumerador()*valor.getDenominador();
    entero2=getDenominador()*valor.getNumerador();
    return (entero1==entero2);
}

bool CRacional::operator<(const CRacional &valor){
    int entero1, entero2;
    entero1=getNumerador()*valor.getDenominador();
    entero2=getDenominador()*valor.getNumerador();
    return (entero1<entero2);
}

bool CRacional::operator>(const CRacional &valor){
    int entero1, entero2;
    entero1=getNumerador()*valor.getDenominador();
    entero2=getDenominador()*valor.getNumerador();
    return (entero1>entero2);
}

bool CRacional::operator!(){
    return (getNumerador()==0);
}

CRacional& CRacional::operator++(){
    setNumerador(getNumerador()+getDenominador());
    return *this;
}

CRacional CRacional::operator++(int num){
    CRacional copia=*this;
    copia.setNumerador(getNumerador()+getDenominador());
    return copia;
}

CRacional& CRacional::operator--(){
    setNumerador(getNumerador()-getDenominador());
    return *this;
}

CRacional CRacional::operator--(int num){
    CRacional copia=*this;
    copia.setNumerador(getNumerador()-getDenominador());
    return copia;
}

CRacional::operator double(){
    return static_cast<double>(getNumerador())/getDenominador();
}

//CRacional& CRacional::Simplificar(){
// // Máximo común divisor. Algoritmo de Euclides
// long mcd, temp, resto;
// mcd = labs(numerador);
// temp = denominador;
// while (temp > 0)
// {
// resto = mcd % temp;
// mcd = temp;
// temp = resto;
// }
// // Simplificar
// if (mcd > 1)
// {
// numerador /= mcd;
// denominador /= mcd;
// }
// return *this;
// }
