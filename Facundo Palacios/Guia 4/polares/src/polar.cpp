#include "polar.h"
#include "../complejos.h"
#include <iostream>
#include <cmath>

polar::polar()
{
    SetfModulo(0.0);
    SetfFase(0.0);
}

polar::polar(float modulo, float fase)
{
    SetfModulo(modulo);
    SetfFase(fase);
}

polar::~polar()
{
    //dtor
}

float polar::Modulo(const complejos& other)
{
    float real=other.Getreal();
    float imaginario=Getimaginario();
    float mod=sqrt(real*real+imaginario*imaginario);
    return mod;
}

float polar::Fase(const complejos& other)
{
    float real=other.Getreal();
    float imaginario=other.Getimaginario();
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

float polar::Modulo()
{
    return GetfModulo();
}

complejos Rectang(float modulo,float fase)
{
    complejos nuevo;
    float real=modulo*cos(fase);
    float imaginario=modulo*sin(fase);
    nuevo.Setreal(real);
    nuevo.Setimaginario(imaginario);
    return nuevo;
}

polar& polar::operator=(const complejos& other)
{
    SetfModulo(Modulo(other));
    SetfFase(Fase(other));
    return *this;
}
