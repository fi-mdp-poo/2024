#include "persona.h"

persona::persona(string _nombre, int _documento, CFecha _fecha)
:nacimiento(_fecha.GetDay(),_fecha.GetMonth(),_fecha.GetYear())
{
    nombre = _nombre;
    documento = _documento;
}

persona::~persona()
{
    //dtor
}

string persona::GetNombre()
{
    return(nombre);
}

int persona::GetDocument()
{
    return(documento);
}

CFecha persona::GetNacimiento()
{
    return(nacimiento);
}

ostream& operator<< (ostream& co,  persona &cmp)
{
    CFecha fecha = cmp.GetNacimiento();

    co << cmp.GetNombre() << endl;
    co << cmp.GetDocument() << endl;
    co << fecha << endl;
    return co;
}
