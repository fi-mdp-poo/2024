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
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;
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

string persona::GetName()
{
    return Name;
}

void persona::SetName(string name)
{
    Name = name;
}

unsigned persona::GetDocument()
{
    return Document;
}

fecha persona::GetBirthDate()
{
    return BirthDate;
}

bool persona::SetDocument(unsigned doc)
{
    Document = doc;

    return true;
}

bool persona:: SetBirthDate(fecha f)
{
     BirthDate = f;

     return true;
}

bool persona:: SetBirthDate(int d, int m, int a)
{
     BirthDate = fecha(d, m, a);

     return true;
}

void persona::vPrint(ostream& co)
{
    co << GetName() << endl;
    co << GetDocument() << endl;
    co << GetBirthDate().Day << '/'
         << GetBirthDate().Month << '/'
         << GetBirthDate().Year << "\n\n";
}

ostream& operator<< (ostream& co, persona &per)
{
    per.vPrint(co);

    return co;
}

