#include "PlantaTemporaria.h"

PlantaTemporaria::PlantaTemporaria(string n, int horas, int hijos, bool casado) :
    Empleado(n,horas,hijos,casado)
{
    //ctor
}

PlantaTemporaria::~PlantaTemporaria()
{
    //dtor
}

 float PlantaTemporaria::calcularSalario() const
 {
     float salario=(GethorasTrabajadas()*20)+calcularSalarioFamiliar();
     return salario;
 }
