#include "cFecha.h"

cFecha::cFecha()
{
    //ctor
}

cFecha::~cFecha()
{
    //dtor
}

ostream& operator<< (ostream& os, cFecha& f)
{
    os  <<" "<< f.Getdia()<<"/"
        << f.Getmes()<<"/"
        << f.Getano()<<"/";
}
