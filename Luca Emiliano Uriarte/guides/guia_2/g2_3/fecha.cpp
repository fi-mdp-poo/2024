#include "fecha.h"

using namespace std;

fecha::fecha() {
    dia = 1;
    mes = 1;
    anio = 2000;
}

void fecha::establecer_fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

void fecha::establecer_dia(int dia) {
    this->dia = dia;
}

void fecha::establecer_mes(int mes) {
    this->mes = mes;
}

void fecha::establecer_anio(int anio) {
    this->anio = anio;
}

void fecha::ingresar_fecha() {
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    if (!validar_fecha()) {
        cerr << "Fecha invalida. Reingrese.\n";
        ingresar_fecha();
    }
}

void fecha::imprimir_la() const {
    cout << (dia < 10 ? "0" : "") << dia << "/"
         << (mes < 10 ? "0" : "") << mes << "/"
         << anio << "\n";
}

void fecha::imprimir_us() const {
    cout << (mes < 10 ? "0" : "") << mes << "/"
         << (dia < 10 ? "0" : "") << dia << "/"
         << anio << "\n";
}

void fecha::imprimir_letras() const {
    cout << dia << " de " << mes_en_letras() << " de " << anio << "\n";
}

const char* fecha::mes_en_letras() const {
    static const char* meses[] = {
        "enero", "febrero", "marzo", "abril", "mayo", "junio",
        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
    };
    return (mes >= 1 && mes <= 12) ? meses[mes - 1] : "mes invalido";
}

bool fecha::validar_fecha() const {
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1)
        return false;

    static const int dias_por_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int max_dias = dias_por_mes[mes - 1];

    // Comprobación de año bisiesto para febrero
    if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))) {
        max_dias = 29;
    }

    return dia <= max_dias;
}
