#include "CFigura.h"

CFigura::CFigura()
{
    //ctor
}

CFigura::~CFigura()
{
    //dtor
}

void CFigura::vSetForeColor(CColor c)
{
    Color_linea = c;
}

void CFigura::vSetBackColor(CColor c)
{
    Color_fondo = c;
}


CColor CFigura::colGetForeColor()
{
    return Color_linea;
}
CColor CFigura::colGetBackColor()
{
    return Color_fondo;
}

void CFigura::SetArea(double a)
{
    Area = a;
}
double CFigura::GetArea()
{
    return Area;
}

void CFigura::SetValores(float v)
{

}




ostream& operator<< (ostream& os, CFigura& f)
{
    os<< "BackColor" <<endl;
    CColor a = f.colGetBackColor();
    os<< a <<endl;
    a = f.colGetForeColor();
    os<< "ForeColor"<<endl;
    os<< a << endl;
}
