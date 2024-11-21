#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>
#include <cstdlib>

class fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    fecha();

    void establecer_fecha(int dia, int mes, int anio);
    void establecer_dia(int dia);
    void establecer_mes(int mes);
    void establecer_anio(int anio);

    void ingresar_fecha();
    void imprimir_la() const;
    void imprimir_us() const;
    void imprimir_letras() const;
    const char* mes_en_letras() const;
    bool validar_fecha() const;
};

#endif // FECHA_H