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
    persona(nombre, doc, nac)
{
    stCategoria = cat;
    fechaIngreso = ingreso;
    fSueldo = sueldo;
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

void vPrint(empleado &emp)
{
    cout << emp.GetName() << endl;
    cout << emp.GetDocument() << endl;
    cout << emp.GetBirthDate().Day << '/'
         << emp.GetBirthDate().Month << '/'
         << emp.GetBirthDate().Year << endl
         << emp.stGetCategoria() << endl
         << emp.fechaGetIngreso().Day << '/'
         << emp.fechaGetIngreso().Month << '/'
         << emp.fechaGetIngreso().Year << endl
         << emp.fGetSueldo() << "\n\n";
}

ostream& operator<< (ostream& co, empleado &emp)
{
    co   << "Nombre = " << emp.GetName() << endl
         << "Documento = " << emp.GetDocument() << endl
         << "Fecha nacimiento = " << emp.GetBirthDate().Day << '/'
         << emp.GetBirthDate().Month << '/' << emp.GetBirthDate().Year << endl
         << "Categoria = " << emp.stGetCategoria() << endl
         << "Fecha ingreso = " << emp.fechaGetIngreso().Day << '/'
         << emp.fechaGetIngreso().Month << '/' << emp.fechaGetIngreso().Year << endl
         << "Sueldo = " << emp.fGetSueldo() << "\n\n";

    return co;
}
