#include "persona.h"
#include <ctime>

fecha::fecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    Day = now->tm_mday;
    Month = (now->tm_mon + 1);
    Year = (now->tm_year + 1900);
}

fecha::fecha(int d, int m, int a)
{
    Day = d;
    Month = m;
    Year = a;
}

persona::persona(string nombre, unsigned numero, fecha ddmmaa)
{
    Name = nombre;
    Document = numero;
    BirthDate = ddmmaa;
}

/***
persona::persona(string nombre, unsigned numero, fecha ddmmaa) :
    Name(nombre), Document(numero), BirthDate(ddmmaa)
{
    ;
}
***/

persona::~persona()
{
    return ;
}

void persona::SetName(string nombre)
{
    Name = nombre;
}

bool persona::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool persona::SetBirthDate(fecha ddmmaa)
{
    BirthDate = ddmmaa;

    return true;
}

bool persona::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

string persona::GetName()
{
    return Name;
}

unsigned persona::GetDocument()
{
    return Document;
}

fecha persona::GetBirthDate()
{
    return BirthDate;
}

void print(persona &per)
{
    cout << per.GetName() << endl;
    cout << per.GetDocument() << endl;
    cout << per.GetBirthDate().Day << '/'
         << per.GetBirthDate().Month << '/'
         << per.GetBirthDate().Year << "\n\n";
}

ostream& operator<< (ostream& co, persona &per)
{
    co << per.GetName() << endl;
    co << per.GetDocument() << endl;
    co << per.GetBirthDate().Day << '/'
         << per.GetBirthDate().Month << '/'
         << per.GetBirthDate().Year << "\n\n";

    return co;
}
