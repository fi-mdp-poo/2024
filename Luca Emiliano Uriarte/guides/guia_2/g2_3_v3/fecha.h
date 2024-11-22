#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int day;
    int month;
    int year;
public:
    Fecha();
    void setFecha(int day, int month, int year);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void ingresarFecha();
    void imprimir_la();
    void imprimir_us();
    void imprimir_letras();
    const char* mesLetras();
    bool validarFecha();
};

#endif // FECHA_H