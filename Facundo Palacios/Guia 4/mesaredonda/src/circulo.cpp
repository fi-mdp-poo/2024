#include "circulo.h"
#include <iostream>

using namespace std;

circulo::circulo()
{

}

circulo::circulo(float radio)
{
    Setradio(radio);
}

circulo::~circulo()
{
    //dtor
}

float circulo::area()
{
    float area;
    float radio=Getradio();
    area=3.141592654*radio*radio;
    return area;
}
