#include <iostream>
#include "claseEmpleado.h"

using namespace std;

Empleado::Empleado(string nom, Fecha ing, unsigned hijos, unsigned horas, bool cas){
    setNombre(nom);
    setFechaIngreso(ing);
    setCantHijos(hijos);
    setHsTrabajo(horas);
    setCasado(cas);
    setSalario(0.0);
}

Empleado::~Empleado(){  }

void Empleado::setNombre(string nom){ nombre=nom; }
void Empleado::setFechaIngreso(const Fecha &ing){ ingreso=ingreso; }
void Empleado::setCantHijos(unsigned int hijos){ hijos=cantHijos; }
void Empleado::setHsTrabajo(unsigned int horas){ hsTrabajo=horas; }
void Empleado::setCasado(bool cas){ casado=cas; }
void Empleado::setSalario(double sal){ salario=sal; }

string Empleado::getNombre()const{ return nombre; }
Fecha Empleado::getIngreso()const{ return ingreso; }
unsigned int Empleado::getCantHijos()const{ return cantHijos; }
unsigned int Empleado::getHsTrabajo()const{ return hsTrabajo; }
bool Empleado::getCasado()const{return casado; }
double Empleado::getSalario()const{ return salario; }

int Empleado::calcularAntiguedad(const Fecha &fecha){
    return (fecha.getYear()-ingreso.getYear());
}

double Empleado::salarioFamiliar(){
    double bonus;
    (casado)? bonus=cantHijos*20+10 : bonus=cantHijos*20;
    return bonus;
}
