#include "fecha.h"

int main() {
    fecha fecha;

    std::cout << "Probando la clase Fecha:\n";

    // Ingresar y validar fecha
    fecha.ingresar_fecha();

    // Mostrar la fecha en diferentes formatos
    std::cout << "\nFormato LA (DD/MM/AAAA): ";
    fecha.imprimir_la();

    std::cout << "Formato US (MM/DD/AAAA): ";
    fecha.imprimir_us();

    std::cout << "Formato con letras: ";
    fecha.imprimir_letras();

    // Modificar la fecha
    fecha.establecer_fecha(15, 8, 2021);
    std::cout << "\nNueva fecha configurada (15/08/2021):\n";
    fecha.imprimir_la();

    return 0;
}