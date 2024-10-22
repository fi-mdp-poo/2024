#include "Contribuyente.h"

/// Constructores y Destructores ///

Contribuyente::Contribuyente(){}

Contribuyente::~Contribuyente(){}

Limitado::Limitado(){}

Limitado::~Limitado(){}

Completo::Completo(){}

Completo::~Completo(){}

Extendido::Extendido(){}

Extendido::~Extendido(){}

/// Metodos ///

float Limitado::calcularMontoVariable(const Factura& factura) const{
    return factura.getMonto() * 0.005;
}

float Completo::calcularMontoVariable(const Factura& factura) const{
    return (factura.getMonto() > 5000) ? factura.getMonto() * 0.5 : 0;
}

float Extendido::calcularMontoVariable(const Factura& factura) const{
    return Completo::calcularMontoVariable(factura) + 10;
}
