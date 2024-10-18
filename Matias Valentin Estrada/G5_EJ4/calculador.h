#ifndef CALCULADOR_H
#define CALCULADOR_H

#include "contribuyente.h"
#include "recibo.h"

using namespace std;

class Calculador{
    private:
        float montoFijo = 5.0;

    public:
        ReciboDePago calcularImpuesto(const Contribuyente& contribuyente, int facturaInicio, int facturaFin);
};

#endif
