#include "MesaRedonda.h"
#include <iostream>

using namespace std;


MesaRedonda::MesaRedonda()
{
    //ctor
}

MesaRedonda::~MesaRedonda()
{
    //dtor
}

MesaRedonda::MesaRedonda(int color, float altura, float radio):
    mesa(altura),
    circulo(radio)
    {
        Setcolor(color);
    }

ostream& operator<<(ostream& os, MesaRedonda& me)
{
    os<<"Mesa redonda: "<<endl
    <<"-Altura: "<<me.mesa::Getaltura()<< " metros "<<endl
    <<"-Area de la mesa: "<<me.circulo::area()<< " metros cuadrados "<<endl
    <<"-Color: "<<me.Getcolor()<<endl;
    return os;
}
