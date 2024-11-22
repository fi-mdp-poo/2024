#include "fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha fecha;

    cout << "Demostración de la clase Fecha\n";

    // Configurar una fecha válida
    fecha.set_fecha(15, 8, 2023);
    cout << "Fecha configurada (LA): ";
    fecha.imprimir_la();

    cout << "Fecha configurada (US): ";
    fecha.imprimir_us();

    cout << "Fecha configurada en letras: ";
    fecha.imprimir_letras();

    // Ingresar una fecha desde el usuario
    cout << "\nIngresar una nueva fecha:\n";
    fecha.ingresar_fecha();
    cout << "Fecha ingresada (LA): ";
    fecha.imprimir_la();

    cout << "Fecha ingresada en letras: ";
    fecha.imprimir_letras();

    return 0;
}
