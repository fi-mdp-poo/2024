#include "calculador.h"

ReciboDePago Calculador::calcularImpuesto(const Contribuyente& contribuyente, int facturaInicio, int facturaFin){
    float total = 0;
    float montoVariable = 0;
    const vector<Factura>& facturas = contribuyente.getFacturas();

    for(const Factura& f : facturas){
        if(f.getNumero() >= facturaInicio && f.getNumero() <= facturaFin){
            total += f.getMonto();
            montoVariable += contribuyente.calcularMontoVariable(f);
        }
    }

    float montoTotal = total + montoFijo + montoVariable;
    return ReciboDePago(contribuyente.getNombre(), montoTotal, montoFijo, montoVariable, facturaInicio, facturaFin);
}
