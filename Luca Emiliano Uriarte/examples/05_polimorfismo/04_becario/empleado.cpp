#include "empleado.h"

empleado::empleado()
{
    //ctor
}

empleado::~empleado()
{
    //dtor
}

empleado::empleado(string nombre, unsigned doc, fecha nac,
                   string cat, fecha ingreso, float sueldo):
    persona(nombre, doc, nac),
    stCategoria(cat), fechaIngreso(ingreso), fSueldo(sueldo)
{
    ;
}

empleado::empleado(string nombre, unsigned doc, int dia, int mes, int anio,
                   string cat, int ding, int ming, int aing, float sueldo):
    persona(nombre, doc),
    stCategoria(cat), fSueldo(sueldo)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;
    fechaIngreso.Day = ding;
    fechaIngreso.Month = ming;
    fechaIngreso.Year = aing;
}
/**
void empleado::SetName(string nombre)
{
    Name = nombre;
}**/
bool empleado::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool empleado::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;

    return true;
}

bool empleado::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

void empleado::vSetIngreso(int dd, int mm, int aa)
{
    fechaIngreso.Day = dd;
    fechaIngreso.Month = mm;
    fechaIngreso.Year = aa;
}

string empleado::stGetCategoria()
{
    return stCategoria;
}

void empleado::vSetCategoria(string val)
{
    stCategoria = val;
}

void empleado::vSetIngreso(fecha val)
{
    fechaIngreso = val;
}

fecha empleado::fechaGetIngreso()
{
    return fechaIngreso;
}

float empleado::fGetSueldo()
{
    return fSueldo;
}

void empleado::vSetSueldo(float val)
{
    fSueldo = val;
}

void empleado::vPrint(ostream& co)
{
    co   << "Nombre = " << GetName() << endl
         << "Documento = " << GetDocument() << endl
         << "Fecha nacimiento = " << GetBirthDate().Day << '/'
         << GetBirthDate().Month << '/' << GetBirthDate().Year << endl
         << "Categoria = " << stGetCategoria() << endl
         << "Fecha ingreso = " << fechaGetIngreso().Day << '/'
         << fechaGetIngreso().Month << '/' << fechaGetIngreso().Year << endl
         << "Sueldo = " << fGetSueldo() << "\n\n";
}

ostream& operator<< (ostream& co, empleado &emp)
{
    emp.vPrint(co);

    return co;
}
