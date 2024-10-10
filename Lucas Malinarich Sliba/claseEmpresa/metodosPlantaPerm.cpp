#include <iostream>
#include "claseEmpleado.h"

using namespace std;

PlantaPerm::PlantaPerm(string nom, Fecha ing, unsigned hijos, unsigned horas, bool cas){
    setNombre(nom);
    setFechaIngreso(ing);
    setCantHijos(hijos);
    setHsTrabajo(horas);
    setCasado(cas);
    setSalario(0.0);
}

PlantaPerm::~PlantaPerm(){  }

double PlantaPerm::calcularSalario(int antiguedad){
    double sueldo=getHsTrabajo()*30+salarioFamiliar()+antiguedad*10;
    return sueldo;
}
