#include "Contribuyente.h"

Contribuyente::Contribuyente(const string& nombre) {
    _nombre = nombre;
}

string Contribuyente::getNombre() const {
    return _nombre;
}

Limitado::Limitado(const string& nombre) : Contribuyente(nombre) {
}

double Limitado::calcularMontoVariable(const double monto) const {
    return monto * 0.005;
}

Completo::Completo(const string& nombre) : Contribuyente(nombre) {
}

double Completo::calcularMontoVariable(const double monto) const {
    double montoVariable = 0.0;
    if (monto > 5000) {
        montoVariable = monto * 0.5;
    }

    return montoVariable;
}

Extendido::Extendido(const string& nombre) : Completo(nombre) {
}

double Extendido::calcularMontoVariable(const double monto) const {
    return Completo::calcularMontoVariable(monto) + 10; // $10 adicionales por cada factura
}
