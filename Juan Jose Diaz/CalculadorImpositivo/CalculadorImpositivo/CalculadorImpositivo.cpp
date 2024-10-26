#include "CalculadorImpositivo.h"

CalculadorImpositivo::CalculadorImpositivo() = default;

void CalculadorImpositivo::inicializar(const string& nombreContribuyente, const CategoriaEnum categoria) {
    _contribuyente = ContribuyenteFactory::crear(nombreContribuyente, categoria);
}

void CalculadorImpositivo::agregarFactura(const string& detalle, const int numeroFactura, const double monto) {
    _facturas.push_back(new Factura(detalle, numeroFactura, monto));
}

ReciboDePago CalculadorImpositivo::calcularImpuesto(const int numFacturaInicio, const int numFacturaFin) const {
    double montoTotal = 0.0;
    double montoVariable = 0.0;

    for (const Factura* factura: _facturas) {
        if (factura->getNumeroFactura() >= numFacturaInicio && factura->getNumeroFactura() <= numFacturaFin) {
            montoTotal += factura->getMonto();
            montoVariable += _contribuyente->calcularMontoVariable(factura->getMonto());
        }
    }

    ReciboDePago reciboDePago(
        _contribuyente->getNombre(),
        montoTotal,
        _montoFijo,
        montoVariable,
        numFacturaInicio,
        numFacturaFin
    );

    return reciboDePago;
}

CalculadorImpositivo::~CalculadorImpositivo() {
    for (const Factura* factura: _facturas) {
        delete factura;
    }
}

