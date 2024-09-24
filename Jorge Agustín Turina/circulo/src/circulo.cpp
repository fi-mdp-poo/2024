#include "circulo.h"

circulo::circulo()
{
    //ctor
}

circulo::~circulo()
{
    //dtor
}

int circulo::Getradio()
{
    return radio;
}

int circulo::Getarea()
{
    return area;
}

void circulo::Setradio(int val)
{ radio = val;
 }

