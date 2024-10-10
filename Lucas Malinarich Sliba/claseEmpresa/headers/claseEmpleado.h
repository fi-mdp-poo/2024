#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "claseFecha.h"
#include <iostream>

using namespace std;

class Empleado{
private:
    string nombre;
    Fecha ingreso;
    unsigned int cantHijos, hsTrabajo;
    bool casado;
    double salario;
public:
    Empleado(string nom="\0", Fecha ing=Fecha(0, 0, 0), unsigned hijos=0, unsigned horas=0, bool cas=false);
    virtual ~Empleado();

    void setNombre(string);
    void setFechaIngreso(const Fecha&);
    void setCantHijos(unsigned int);
    void setHsTrabajo(unsigned int);
    void setCasado(bool);
    void setSalario(double);

    string getNombre()const;
    Fecha getIngreso()const;
    unsigned int getCantHijos()const;
    unsigned int getHsTrabajo()const;
    bool getCasado()const;
    double getSalario()const;

    int calcularAntiguedad(const Fecha&);
    virtual double salarioFamiliar();
    virtual double calcularSalario(int antiguedad)=0;
};

class PlantaPerm : public Empleado{
public:
    PlantaPerm(string nom="\0", Fecha ing=Fecha(0, 0, 0), unsigned hijos=0, unsigned horas=0, bool cas=false);
    virtual ~PlantaPerm();
    virtual double calcularSalario(int antiguedad);
};

class PlantaTemp : public Empleado{
public:
    PlantaTemp(string nom="\0", Fecha ing=Fecha(0, 0, 0), unsigned hijos=0, unsigned horas=0, bool cas=false);
    virtual ~PlantaTemp();
    virtual double calcularSalario(int antiguedad);
};

class Gerente : public Empleado{
public:
    Gerente(string nom="\0", Fecha ing=Fecha(0, 0, 0), unsigned hijos=0, unsigned horas=0, bool cas=false);
    virtual ~Gerente();
    double calcularSalario(int antiguedad);
};

#endif // CLASEEMPLEADO_H_INCLUDED
