#include "fecha.h"
#include <iostream>
#include <map>
using namespace std;

// Constructor por defecto
Fecha::Fecha() : day(1), month(1), year(2000) {}

// Métodos de configuración
void Fecha::set_fecha(int dia, int mes, int anio) {
    day = dia;
    month = mes;
    year = anio;
}

void Fecha::set_day(int dia) { day = dia; }
void Fecha::set_month(int mes) { month = mes; }
void Fecha::set_year(int anio) { year = anio; }

// Método auxiliar para obtener el nombre del mes en letras
string Fecha::obtener_mes_letras(int mes) const {
    const map<int, string> meses = {
        {1, "Enero"}, {2, "Febrero"}, {3, "Marzo"},
        {4, "Abril"}, {5, "Mayo"}, {6, "Junio"},
        {7, "Julio"}, {8, "Agosto"}, {9, "Septiembre"},
        {10, "Octubre"}, {11, "Noviembre"}, {12, "Diciembre"}
    };
    return meses.count(mes) ? meses.at(mes) : "Mes inválido";
}

// Método auxiliar para validar un año bisiesto
bool Fecha::es_bisiesto(int anio) const {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Método para ingresar fecha desde el usuario
void Fecha::ingresar_fecha() {
    cout << "Ingrese el día: ";
    cin >> day;
    cout << "Ingrese el mes: ";
    cin >> month;
    cout << "Ingrese el año: ";
    cin >> year;
    if (!validar_fecha()) {
        cout << "Fecha inválida. Se reinicia a 1/1/2000.\n";
        day = 1; month = 1; year = 2000;
    }
}

// Método para validar la fecha
bool Fecha::validar_fecha() const {
    if (month < 1 || month > 12 || day < 1) return false;

    const int dias_por_mes[] = {31, 28 + es_bisiesto(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day <= dias_por_mes[month - 1];
}

// Métodos para imprimir la fecha en diferentes formatos
void Fecha::imprimir_la() const {
    cout << day << "/" << month << "/" << year << endl;
}

void Fecha::imprimir_us() const {
    cout << month << "-" << day << "-" << year << endl;
}

void Fecha::imprimir_letras() const {
    cout << day << " de " << obtener_mes_letras(month) << " de " << year << endl;
}