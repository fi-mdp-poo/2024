#include "Empleado.h"
#include <iostream>
#include <cstring>

using namespace std;

Empleado::Empleado(const std::string& nombres, const std::string& apellidos, const Fecha& fechaContratacion, const Fecha& fechaNacimiento)
    : nombres(nombres), apellidos(apellidos), fechacontratacion(fechaContratacion), fechanacimiento(fechaNacimiento) {}

Empleado::~Empleado() {}

void Empleado::imprimir() const
{
    // Print details in the requested format
    cout << apellidos << ", " << nombres << endl;
    cout << "Contratado el: " << fechacontratacion.Getday() << " de "
         << fechacontratacion.mesLetras() << " de " << fechacontratacion.Getyear() << endl;

    cout << "Fecha de nacimiento: " << fechanacimiento.Getday() << " de "
         << fechanacimiento.mesLetras() << " de " << fechanacimiento.Getyear() << endl;
}
