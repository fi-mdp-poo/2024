#include "headers/claseEmpleado.h"

std::ostream& operator<<(std::ostream &Cout, Empleado &empleado){
    return Cout;
}

Empleado::Empleado(std::string cat, const Fecha& ingTrab, float sue){
    setCategoria(cat);
    setIngTrabajo(ingTrab);
    setSueldo(sue);
}

Empleado::~Empleado(){  }
void Empleado::setCategoria(std::string cat){ categoria=cat; }
void Empleado::setIngTrabajo(const Fecha &ingTrab){ ingTrabajo=ingTrab; }
void Empleado::setSueldo(float sue){ sueldo=sue; }

std::string Empleado::getCategoria()const{ return categoria; }
Fecha Empleado::getIngTrabajo()const{ return ingTrabajo; }
float Empleado::getSueldo()const{ return sueldo; }
