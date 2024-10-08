#include "becario.h"

becario::becario()
{
    //ctor
}

becario::~becario()
{
    //dtor
}

becario::becario(string nombre, unsigned doc, fecha fe,
                 string carrera, fecha ing, int cant, float pro,
                 string cat, fecha ding, float sueldo,
                 string tipo, int dur, string lab, string dir) :
//    estudiante(nombre, doc, fe, carrera, ing, cant, pro),
    empleado(nombre, doc, fe, cat, ding, sueldo),
    estudiante(nombre, doc, fe, carrera, ing, cant, pro),
    stTipo(tipo), iDuracion(dur), stLaboratorio(lab), stDirector(dir)
{
    ;
}

void becario::SetName(string nombre)
{
    Name = nombre;
}

string becario::stGetTipo()
{
    return stTipo;
}

bool becario::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool becario::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;

    return true;
}

bool becario::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

void becario::vSetTipo(string val)
{
    stTipo = val;
}

int becario::iGetDuracion()
{
    return iDuracion;
}

void becario::vSetDuracion(int val)
{
    iDuracion = val;
}

string becario::stGetLaboratorio()
{
    return stLaboratorio;
}

void becario::vSetLaboratorio(string val)
{
    stLaboratorio = val;
}

string becario::stGetDirector()
{
    return stDirector;
}

void becario::vSetDirector(string val)
{
    stDirector = val;
}

void becario::vPrint(ostream& co)
{
    co   << "Nombre = " << GetName() << endl
         << "Documento = " << GetDocument() << endl
         << "Fecha Nacimiento = " << GetBirthDate().Day << '/'
         << GetBirthDate().Month << '/'
         << GetBirthDate().Year << endl
         << "Categoria = " << stGetCategoria() << endl
         << "Fecha Ingreso = " << empleado::fechaGetIngreso().Day << '/'
         << empleado::fechaGetIngreso().Month << '/'
         << empleado::fechaGetIngreso().Year << endl
         << "Sueldo = " << fGetSueldo() << endl
         << "Carrera = " << stGetCarrera() << endl
         << "Fecha Ingreso = " << estudiante::fechaGetIngreso().Day << '/'
         << estudiante::fechaGetIngreso().Month << '/'
         << estudiante::fechaGetIngreso().Year << endl
         << "Cantidad de materias = " << iGetMaterias() << endl
         << "Promedio = " << fGetPromedio() << endl
         << "Tipo de beca = " << stGetTipo() << endl
         << "Duracion = " << iGetDuracion() << endl
         << "Lugar trabajo = " << stGetLaboratorio() << endl
         << "Nombre director = " << stGetDirector() << "\n\n";
}

ostream& operator<< (ostream& co, becario &bec)
{
    bec.vPrint(co);

    return co;
}
