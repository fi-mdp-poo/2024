#ifndef COMPOSICION_H
#define COMPOSICION_H

#include <iostream>
#include <vector>

using namespace std;

class Cedula {
public:
    Cedula(const string& nombre_val, int dni_val, bool es_titular_val);
    void mostrar_informacion() const;

private:
    string nombre;
    int dni;
    bool es_titular;
};

class Infraccion {
public:
    Infraccion(const string& lugar_val, const string& motivo_val, int costo_val);
    void mostrar_informacion() const;
private:
    string lugar;
    string motivo;
    int costo;
};

class Auto {
public:
    Auto(const string& modelo_val);
    void mostrar_informacion() const;
    void agregar_cedula(const string& nombre_val, int dni_val, bool es_titular_val);
    void agregar_infraccion(const string& lugar_val, const string& motivo_val, int costo_val);

private:
    string modelo;
    vector<Cedula> cedulas;
    vector<Infraccion> infracciones;
};

#endif
