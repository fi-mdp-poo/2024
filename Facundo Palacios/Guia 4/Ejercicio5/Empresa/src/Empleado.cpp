#include "Empleado.h"
#include <string>

using namespace std;

Empleado::Empleado(string n, int horas, int hijos, bool casado)
{
    Setnombre(n);
    SethorasTrabajadas(horas);
    Sethijos(hijos);
    Setcasado(casado);
}

Empleado::~Empleado()
{
    //dtor
}

float Empleado::calcularSalarioFamiliar() const
{
    float salarioFamiliar=Gethijos()*20; //$20 por hijo
    if(Getcasado())
    {
        salarioFamiliar+=10; //$10 por casado
    }
    return salarioFamiliar;
}
