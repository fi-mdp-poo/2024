#include "ReciboDePago.h"

ReciboDePago::ReciboDePago(
            const string& nombreContribuyente,
            const double montoTotal,
            const double montoFijo,
            const double montoVariable,
            const int primeraFactura,
            const int ultimaFactura
        ) {
    _nombreContribuyente = nombreContribuyente;
    _montoTotal = montoTotal;
    _montoFijo = montoFijo;
    _montoVariable = montoVariable;
    _primeraFactura = primeraFactura;
    _ultimaFactura = ultimaFactura;
}

string ReciboDePago::getNombreDelContribuyente() const {
    return _nombreContribuyente;
}

double ReciboDePago::getMontoTotal() const {
    return _montoTotal;
}

double ReciboDePago::getMontoFijo() const {
    return _montoFijo;
}

double ReciboDePago::getMontoVariable() const {
    return _montoVariable;
}

int ReciboDePago::getPrimeraFacturaConsiderada() const {
    return _primeraFactura;
}

int ReciboDePago::getUltimaFacturaConsiderada() const {
    return _ultimaFactura;
}
