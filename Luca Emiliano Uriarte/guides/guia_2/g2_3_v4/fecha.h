#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int day;
    int month;
    int year;

public:
    Fecha(); // Constructor por defecto
    void setFecha(int day, int month, int year);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void ingresarFecha();
    void imprimir_la();    // formato latinoamericano dd/mm/aaaa
    void imprimir_us();    // formato estadounidense mm/dd/aaaa
    void imprimir_letras(); // formato en letras
    const char* mesLetras();
    bool validarFecha();
};

#endif