#include "Empresa.h"

Empresa::Empresa()
{
    //ctor
}

Empresa::~Empresa()
{

}

void Empresa::agregarEmpleado(Empleado* e)
{
    empleados.push_back(e);
}

float Empresa::montoTotal() const
{
    float total=0.0;
    for(const auto& e: empleados)
    {
        total+=e->calcularSalario();
    }
    return total;
}
