#include "fecha.h"
#include <iostream>

using namespace std;

int main() {
    Fecha fecha1;
    cout << "Fecha por defecto: ";
    fecha1.imprimir_la();

    fecha1.setFecha(15, 8, 2021);
    cout << "Fecha modificada con setFecha: ";
    fecha1.imprimir_la();

    fecha1.setDay(12);
    cout << "Fecha después de setDay: ";
    fecha1.imprimir_la();

    fecha1.setMonth(9);
    cout << "Fecha después de setMonth: ";
    fecha1.imprimir_la();

    fecha1.setYear(2023);
    cout << "Fecha después de setYear: ";
    fecha1.imprimir_la();

    cout << "Ingrese una nueva fecha:" << endl;
    fecha1.ingresarFecha();
    cout << "Fecha ingresada: ";
    fecha1.imprimir_la();

    cout << "Fecha en formato US: ";
    fecha1.imprimir_us();

    cout << "Fecha en letras: ";
    fecha1.imprimir_letras();

    if(fecha1.validarFecha()) {
        cout << "La fecha es válida." << endl;
    } else {
        cout << "La fecha es inválida." << endl;
    }

    cout << "Mes en letras: " << fecha1.mesLetras() << endl;

    return 0;
}