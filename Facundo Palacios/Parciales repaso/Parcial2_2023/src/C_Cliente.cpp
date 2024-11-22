#include "C_Cliente.h"

C_Cliente::C_Cliente()
{

}

C_Cliente::~C_Cliente()
{
    //dtor
}

ostream& operator <<(ostream& os, C_Cliente& actual)
{
    os<<"Cliente:"<< actual.Getnombre_cliente()<< ", "<< actual.Getcuit();
    return os;
}
