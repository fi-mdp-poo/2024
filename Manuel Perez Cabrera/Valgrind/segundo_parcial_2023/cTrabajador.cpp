#include "cTrabajador.h"

cTrabajador::cTrabajador(string n)
{
    nombre = n;
}

cTrabajador::~cTrabajador()
{
    //dtor
}

ostream& operator<< (ostream& os, cTrabajador& c)
{
    os << "     Trabajador: " <<c.Getnombre();

    cFecha a = c.Getfecha_ingreso();
    os << a << c.Getcodigo();


return os;
}
