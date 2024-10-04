#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "claseFecha.h"

using namespace std;

class Empleado{
private:
    string nombre;
    Fecha ingreso;
    unsigned int cantHijos;
    bool casado;
    double salario;
public:
    Empleado(string nom="\0", Fecha ing=Fecha(0, 0, 0), unsigned hijos=0, bool cas=false);
    virtual ~Empleado();

    void setNombre(string);
    void setFecha(const Fecha&);
    void setCantHijos(unsigned int);
    void setCasado(bool);
    void setSalario(double);

    string getNombre()const;
    Fecha getIngreso()const;
    unsigned int getCantHijos()const;
    bool getCasado()const;
    double getSalario()const;

    int calcularAntiguedad(const Fecha&);
    virtual double calcularSalario(int antiguedad)=0;
};

class PlantaPerm : public Empleado{
public:
    double calcularSalario();
};

class PlantaTemp : public Empleado{
public:
    double calcularSalario();
};

class Gerente : public Empleado{
public:
    double calcularSalario();
};

#endif // CLASEEMPLEADO_H_INCLUDED
