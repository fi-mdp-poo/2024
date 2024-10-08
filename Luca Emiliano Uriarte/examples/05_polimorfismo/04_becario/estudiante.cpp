#include "estudiante.h"

estudiante::estudiante(string nombre, unsigned doc, fecha nac,
                       string carrera, fecha ingreso, int cant, float prom):
    persona(nombre, doc, nac)
{
    stCarrera = carrera;
    fechaIngreso = ingreso;
    iMaterias = cant;
    fPromedio = prom;
}

estudiante::estudiante():persona()
{
    stCarrera = " ";
    fechaIngreso = fecha(1,1,1900);
    iMaterias = 0;
    fPromedio = 0.0;
}

estudiante::~estudiante()
{
    //dtor
}

void estudiante::SetName(string nombre)
{
    Name = nombre;
}

bool estudiante::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool estudiante::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;

    return true;
}

bool estudiante::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

string estudiante::stGetCarrera()
{
    return stCarrera;
}

void estudiante::vSetCarrera(string val)
{
    stCarrera = val;
}

fecha estudiante::fechaGetIngreso()
{
    return fechaIngreso;
}

void estudiante::vSetIngreso(fecha val)
{
    fechaIngreso = val;
}

void estudiante::vSetIngreso(int dd, int mm, int aa)
{
    fechaIngreso.Day = dd;
    fechaIngreso.Month = mm;
    fechaIngreso.Year = aa;
}

int estudiante::iGetMaterias()
{
    return iMaterias;
}

void estudiante::vSetMaterias(int val)
{
    iMaterias = val;
}

float estudiante::fGetPromedio()
{
    return fPromedio;
}

void estudiante::vSetPromedio(float val)
{
    fPromedio = val;
}

void estudiante::vPrint(ostream& co)
{
    co   << "Nombre = " << GetName() << endl
         << "Documento = " << GetDocument() << endl
         << "Fecha nacimiento = " << GetBirthDate().Day << '/'
         << GetBirthDate().Month << '/' << GetBirthDate().Year << endl
         << "Carrera = Ing. " << stGetCarrera() << endl
         << "Fecha ingreso = " << fechaGetIngreso().Day << '/'
         << fechaGetIngreso().Month << '/' << fechaGetIngreso().Year << endl
         << "Cantidad de materias aprobadas = " << iGetMaterias() << endl
         << "Promedio = " << fGetPromedio() << "\n\n";
}

ostream& operator<< (ostream& co, estudiante &est)
{
    est.vPrint(co);

    return co;
}
