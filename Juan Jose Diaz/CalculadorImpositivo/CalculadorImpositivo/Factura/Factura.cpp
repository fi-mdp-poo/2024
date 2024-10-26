#include "Factura.h"

Factura::Factura(const string& detalle, const int numeroFactura, const double monto) {
    _detalle = detalle;
    _numeroFactura = numeroFactura;
    _monto = monto;
}

int Factura::getNumeroFactura() const {
    return _numeroFactura;
}

double Factura::getMonto() const {
    return _monto;
}

/**
 * Cuando el destructor no hace nada particular, asignar `default` permite al compilador optimizar la
 * destruccion de objetos de la clase, además indica explicitamente que no hay liberacion manuales de recursos.
 */
Factura::~Factura() = default;
