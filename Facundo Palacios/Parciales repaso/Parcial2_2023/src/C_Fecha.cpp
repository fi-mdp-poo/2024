#include "C_Fecha.h"

C_Fecha::C_Fecha()
{

}

C_Fecha::~C_Fecha()
{
    //dtor
}

ostream& operator<< (ostream& os, C_Fecha& actual)
{
    os  <<" "<< actual.Getdia()<<","
        << actual.Getmes()<<","
        << actual.Getano();
}
