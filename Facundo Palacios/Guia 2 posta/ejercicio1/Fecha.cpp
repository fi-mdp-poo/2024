#include <iostream>
#include "Fecha.h"

using namespace std;

void Fecha::setFecha(int day, int month, int year)
{
    Setday(day);
    Setmonth(month);
    Setyear(year);
}

void Fecha::ingresarFecha()
{
    cout << "Ingrese el dia: ";
    cin >> day;
    cout << "Ingrese el mes: ";
    cin >> month;
    cout << "Ingrese el ano: ";
    cin >> year;
}

string Fecha::mesLetras() const
{
    static const char* months[]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septirmbre","Octubre","Noviembre","Diciembre"};
    if(month>=1 && month<=12)
    {
        return months[month-1];
    }
    else
    {
        return "Mes invalido";
    }

}

bool Fecha::validarFecha() const
{
    bool isValid = true;

    if (year < 1)
    {
        isValid = false;
    }
    else if (month < 1 || month > 12)
    {
        isValid = false;
    }
    else
    {
        int maxDays;
        if (month == 2)
        {
            maxDays = esBisiesto(year) ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            maxDays = 30;
        }
        else
        {
            maxDays = 31;
        }

        if (day < 1 || day > maxDays)
        {
            isValid = false;
        }
    }

    return isValid;
}
