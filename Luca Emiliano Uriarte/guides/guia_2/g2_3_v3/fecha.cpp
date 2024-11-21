#include "fecha.h"
#include <iostream>

Fecha::Fecha() {
    day = 1;
    month = 1;
    year = 2000;
}

void Fecha::setFecha(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
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
    int d, m, y;
    std::cout << "Ingrese día: ";
    std::cin >> d;
    setDay(d);

    std::cout << "Ingrese mes: ";
    std::cin >> m;
    setMonth(m);

    std::cout << "Ingrese año: ";
    std::cin >> y;
    setYear(y);
}

void Fecha::imprimir_la() {
    std::cout << (day < 10 ? "0" : "") << day << "/"
              << (month < 10 ? "0" : "") << month << "/"
              << year << std::endl;
}

void Fecha::imprimir_us() {
    std::cout << (month < 10 ? "0" : "") << month << "/"
              << (day < 10 ? "0" : "") << day << "/"
              << year << std::endl;
}

void Fecha::imprimir_letras() {
    std::cout << day << " de " << mesLetras() << " de " << year << std::endl;
}

const char* Fecha::mesLetras() {
    const char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                             "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    if(month >=1 && month <=12)
        return meses[month - 1];
    else
        return "Mes inválido";
}

bool Fecha::validarFecha() {
    if (year < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    int maxDay;
    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                maxDay = 29;
            else
                maxDay = 28;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
            break;
    }
    if (day > maxDay)
        return false;
    return true;
}