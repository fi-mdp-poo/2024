#include <iostream>
#include "claseEmpleado.h"

using namespace std;

PlantaTemp::PlantaTemp(string nom, Fecha ing, unsigned hijos, unsigned horas, bool cas){
    setNombre(nom);
    setFechaIngreso(ing);
    setCantHijos(hijos);
    setHsTrabajo(horas);
    setCasado(cas);
    setSalario(0.0);
}

PlantaTemp::~PlantaTemp(){  }

double PlantaTemp::calcularSalario(int antiguedad){
    double sueldo=getHsTrabajo()*20+salarioFamiliar();
    return sueldo;
}
