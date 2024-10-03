#include <iostream>
#include "Fecha.h"
#include "Empleado.h"

using namespace std;

int main()
{
    Fecha fechaContratacion, fechaNacimiento1, fechaNacimiento2;
    fechaContratacion.setFecha(1, 7, 1999);
    fechaNacimiento1.setFecha(31, 12, 1978);
    fechaNacimiento2.setFecha(25, 2, 1980);  // Using the same date for simplicity

    // Create instances of Empleado
    Empleado empleado1("Juan", "Perez", fechaContratacion, fechaNacimiento1);
    Empleado empleado2("Pedro", "Lopez", fechaContratacion, fechaNacimiento2);

    // Print employee details
    empleado1.imprimir();
    cout << endl;  // Add a line break between employees
    empleado2.imprimir();
 return 0;
}
