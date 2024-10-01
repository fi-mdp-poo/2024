#include "PlantaPermanente.h"

PlantaPermanente::PlantaPermanente(string n, int horas, int hijos, bool casado, int antiguedad) :
Empleado(n,horas,hijos,casado)
{
    Setantiguedad(antiguedad);
}

PlantaPermanente::~PlantaPermanente()
{
    //dtor
}

float PlantaPermanente::calcularSalario() const
{
    float salario = (GethorasTrabajadas()*30)+(Getantiguedad()*10)+calcularSalarioFamiliar();
    return salario;
}
