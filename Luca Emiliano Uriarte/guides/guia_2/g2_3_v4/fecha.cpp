#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() {
    day = 1;
    month = 1;
    year = 2023;
}

void Fecha::setFecha(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
    if (!validarFecha()) {
        cout << "Fecha inválida. Se establecerá la fecha por defecto." << endl;
        day = 1;
        month = 1;
        year = 2023;
    }
}

void Fecha::setDay(int d) {
    day = d;
}

void Fecha::setMonth(int m) {
    month = m;
}

void Fecha::setYear(int y) {
    year = y;
}

void Fecha::ingresarFecha() {
    cout << "Ingrese día: ";
    cin >> day;
    cout << "Ingrese mes: ";
    cin >> month;
    cout << "Ingrese año: ";
    cin >> year;
    
    if (!validarFecha()) {
        cout << "Fecha inválida. Se establecerá la fecha por defecto." << endl;
        day = 1;
        month = 1;
        year = 2023;
    }
}

void Fecha::imprimir_la() {
    printf("%02d/%02d/%04d\n", day, month, year);
}

void Fecha::imprimir_us() {
    printf("%02d/%02d/%04d\n", month, day, year);
}

void Fecha::imprimir_letras() {
    cout << day << " de " << mesLetras() << " de " << year << endl;
}

const char* Fecha::mesLetras() {
    const char* meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                          "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    return meses[month - 1];
}

bool Fecha::validarFecha() {
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Verificar año bisiesto
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            diasPorMes[1] = 29;
    }
    
    if (day > diasPorMes[month - 1]) return false;
    
    return true;
}