#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    public:
        Fecha() : day(1),month(1),year(2004){};
        virtual ~Fecha() {};
        void setFecha(int day, int month, int year);

        int Getday() const { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() const { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() const { return year; }
        void Setyear(int val) { year = val; }

        void ingresarFecha();
        string mesLetras() const;
        bool validarFecha() const;

    protected:

    private:
        int day;
        int month;
        int year;

        bool esBisiesto(int year) const {return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);}
};

#endif // FECHA_H
