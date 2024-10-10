#include <iostream>
#include "claseEmpleado.h"

using namespace std;

Gerente::Gerente(string nom, Fecha ing, unsigned hijos, unsigned horas, bool cas){
    setNombre(nom);
    setFechaIngreso(ing);
    setCantHijos(hijos);
    setHsTrabajo(horas);
    setCasado(cas);
    setSalario(0.0);
}

Gerente::~Gerente(){  }

double Gerente::calcularSalario(int antiguedad){
    double sueldo=getHsTrabajo()*40+salarioFamiliar()+antiguedad*15;
    return sueldo;
}
