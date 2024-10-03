#include <iostream>
#include "Tiempo.h"

using namespace std;

int main()
{
      Tiempo t;  // Crear un objeto de la clase Tiempo

    // Mostrar valores iniciales
    std::cout << "Valores iniciales:" << std::endl;
    std::cout << "Hora: " << t.Gethora() << std::endl;
    std::cout << "Minutos: " << t.Getminutos() << std::endl;
    std::cout << "Segundos: " << t.Getsegundos() << std::endl;

    // Ingresar datos
    t.ingresarDatos();

    // Mostrar los datos ingresados
    std::cout << "Datos ingresados:" << std::endl;
    std::cout << "Hora: " << t.Gethora() << std::endl;
    std::cout << "Minutos: " << t.Getminutos() << std::endl;
    std::cout << "Segundos: " << t.Getsegundos() << std::endl;

    // Mostrar en formato estándar
    std::cout << "Hora en formato estandar (12 horas): ";
    t.muestra_fmt_estandard();

    // Mostrar en formato universal
    std::cout << "Hora en formato universal (24 horas): ";
    t.muestra_fmt_universal();
    return 0;
}
