#include "Gerente.h"

Gerente::Gerente(string n, int horas, int hijos, bool casado, int antiguedad):
        PlantaPermanente(n,horas,hijos,casado,antiguedad)
{
    //ctor
}

Gerente::~Gerente()
{
    //dtor
}

float Gerente::calcularSalario() const
{
    float salario=(GethorasTrabajadas()*40)+(Getantiguedad()*15)+calcularSalarioFamiliar();
    return salario;
}
