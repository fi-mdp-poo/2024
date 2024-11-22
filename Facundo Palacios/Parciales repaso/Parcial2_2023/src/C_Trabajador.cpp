#include "C_Trabajador.h"

C_Trabajador::C_Trabajador()
{

}

C_Trabajador::~C_Trabajador()
{
    //dtor
}

void C_Trabajador::Setfecha_ingreso(int d, int m, int a)
{
    fecha_ingreso.Setdia(d);
    fecha_ingreso.Setano(a);
    fecha_ingreso.Setmes(m);
}

ostream& operator <<(ostream& os, C_Trabajador& actual)
{
    C_Fecha fecha= actual.Getfecha_ingreso();
    os<<"Trabajador:"<< actual.Getnombre()<< ", " << fecha << ", " << actual.Getcodigo();
    return os;
}
