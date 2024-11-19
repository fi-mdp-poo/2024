#include "CColor.h"

CColor::CColor()
{
    //ctor
}

CColor::CColor(int c)
{
    color = c;
    alpha = (c & 0xFF000000)>> 3*8;
    b = (c & 0x00FF0000)>> 2*8;
    g = (c & 0x0000FF00)>> 1*8;
    r = (c & 0x000000FF)>> 0*8;

}

CColor::~CColor()
{
    //dtor
}

unsigned char CColor::GetRed()
{
    return r;
}
unsigned char CColor::GetGreen()
{
    return g;
}
unsigned char CColor::GetBlue()
{
    return b;
}
unsigned char CColor::GetAlpha()
{
    return alpha;
}

ostream& operator<< (ostream& os, CColor& c)
{
    os << "Componente rojo : " <<dec<< (int)c.GetRed() <<endl;
    os << "Componente verde : " <<dec<< (int)c.GetGreen() <<endl;
    os << "Componente azul : " <<dec<< (int)c.GetBlue() <<endl;
    os << "Componente alpha : " <<dec<< (int)c.GetAlpha() <<endl;

}
