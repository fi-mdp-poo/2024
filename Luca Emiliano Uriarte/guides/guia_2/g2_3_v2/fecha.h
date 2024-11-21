#ifndef FECHA_H
#define FECHA_H

#include <string>
using namespace std;

class Fecha {
private:
    int day;
    int month;
    int year;

    // Método auxiliar para obtener el nombre del mes en letras
    string obtener_mes_letras(int mes) const;

    // Método auxiliar para validar un año bisiesto
    bool es_bisiesto(int anio) const;

public:
    // Constructor por defecto
    Fecha();

    // Métodos de configuración
    void set_fecha(int dia, int mes, int anio);
    void set_day(int dia);
    void set_month(int mes);
    void set_year(int anio);

    // Método para ingresar fecha desde el usuario
    void ingresar_fecha();

    // Método para validar la fecha
    bool validar_fecha() const;

    // Métodos para imprimir la fecha en diferentes formatos
    void imprimir_la() const;
    void imprimir_us() const;
    void imprimir_letras() const;
};

#endif // FECHA_H