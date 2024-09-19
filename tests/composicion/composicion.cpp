#include "composicion.h"

Cedula::Cedula(const string& nombre_val, int dni_val, bool es_titular_val) {
    nombre = nombre_val;
    dni = dni_val;
    es_titular = es_titular_val;
}

void Cedula::mostrar_informacion() const {
    cout << "Cedula:" << endl;
    cout << "  Nombre: " << nombre << endl;
    cout << "  DNI: " << dni << endl;
    cout << "  Titular: " << (es_titular ? "Si" : "No") << endl;
}

Infraccion::Infraccion(const string& lugar_val, const string& motivo_val, int costo_val) {
    lugar = lugar_val;
    motivo = motivo_val;
    costo = costo_val;
}

void Infraccion::mostrar_informacion() const {
    cout << "Infraccion:" << endl;
    cout << "  Lugar: " << lugar << endl;
    cout << "  Motivo: " << motivo << endl;
    cout << "  Costo: $" << costo << endl;
}

Auto::Auto(const string& modelo_val) {
    modelo = modelo_val;
}

void Auto::agregar_cedula(const string& nombre_val, int dni_val, bool es_titular_val) {
    Cedula nueva_cedula(nombre_val, dni_val, es_titular_val);
    cedulas.push_back(nueva_cedula);
}

void Auto::agregar_infraccion(const string& lugar_val, const string& motivo_val, int costo_val) {
    Infraccion nueva_infraccion(lugar_val, motivo_val, costo_val);
    infracciones.push_back(nueva_infraccion);
}

void Auto::mostrar_informacion() const {
    cout << "Modelo: " << modelo << endl;
    for (const Cedula& cedula : cedulas) {
        cedula.mostrar_informacion();
    }
    for (const Infraccion& infraccion : infracciones) {
        infraccion.mostrar_informacion();
    }
}
