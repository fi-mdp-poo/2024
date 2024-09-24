#include "complejos.h"
#include <cmath>
#include <iostream>

using namespace std;

complejos::complejos(float real, float imaginario)
{
    Setreal(real);
    Setimaginario(imaginario);
}

complejos::complejos(const complejos& other)
{
    Setreal(other.Getreal());
    Setimaginario(other.Getimaginario());
}

complejos::~complejos(){}

//Sobrecarga de la suma
complejos complejos::operator+(const complejos& other)
{
    float real=Getreal()+other.Getreal();
    float imaginario=Getimaginario()+other.Getimaginario();
    complejos sum(real, imaginario);
    return sum;
}

//Sobrecarga de la resta
complejos complejos::operator-(const complejos& other)
{
    float real=Getreal()-other.Getreal();
    float imaginario=Getimaginario()-other.Getimaginario();
    complejos res(real, imaginario);
    return res;
}

//Sobrecarga de la multiplicacion
complejos complejos::operator*(const complejos& other)
{
    float real=Getreal()*other.Getreal()-Getimaginario()*other.Getimaginario();
    float imaginario=Getreal()*other.Getimaginario()+Getimaginario()*other.Getreal();
    complejos multi(real, imaginario);
    return multi;
}

//Sobrecarga de la division
complejos complejos::operator/(const complejos& other)
{
    if(other.Getreal()==0 && other.Getimaginario()==0)
    {
        throw runtime_error("Division por cero, BURRO");
    }
    float divisor=(other.Getreal()*other.Getreal())+(other.Getimaginario()*other.Getimaginario());
    float real=(Getreal()*other.Getreal()+Getimaginario()*other.Getimaginario())/divisor;
    float imaginario=(Getimaginario()*other.Getreal()-Getreal()*other.Getimaginario())/divisor;
    complejos div(real, imaginario);
    return div;
}

//Sobrecarga del igual
complejos& complejos::operator=(const complejos& other)
{
    Setreal(other.Getreal());
    Setimaginario(other.Getimaginario());
    return *this;
}

//Sobrecarga del cout
ostream& operator<<(ostream& os,const complejos& other)
{
    if(other.Getimaginario()>=0.0)
    {
        os<<other.Getreal() << "+" << other.Getimaginario()<<"i"<<endl;
    }
    else
    {
         os<<other.Getreal() << other.Getimaginario()<<"i"<<endl;
    }
    return os;
}

//Sobrecarga del cin
istream& operator>>(istream& is,complejos& other)
{
    float aux;
    cout<<"Parte real: ";
    is>>aux;
    other.Setreal(aux);
    cout<<endl;
    cout<<"Parte imaginaria: ";
    is>>aux;
    other.Setimaginario(aux);
    cout<<endl;
    return is;
}

//Modulo
float complejos::modulo()
{
   float mod=sqrt(Getreal()*Getreal()+Getimaginario()*Getimaginario());
   return mod;
}

//Fase
float complejos::fase()
{
    float real=Getreal();
    float imaginario=Getimaginario();
    float angulo=atan(imaginario/real);
    if (real<0.0 && imaginario>=0.0)
    {
       angulo=3.141592654+angulo;
    }
    else if (real<0.0 && imaginario<0.0)
    {
       angulo=3.141592654+angulo;
    }
    else if (real>=0.0 && imaginario<0.0)
    {
       angulo=2*3.141592654+angulo;
    }
    return angulo;
}
