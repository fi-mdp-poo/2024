#include "CalculadorImpositivo.h"

/// Constructor y Destructor ///
CalculadorImpositivo::CalculadorImpositivo(){}

CalculadorImpositivo::~CalculadorImpositivo(){}

/// Metodos ///
void CalculadorImpositivo::inicializar(const string name, const categ cat){
    nombre = name;

    if(cat == LIMITADO){
        categoria = new Limitado;
    }
    if(cat == COMPLETO){
        categoria = new Completo;
    }
    if(cat == EXTENDIDO){
        categoria = new Extendido;
    }
}

void CalculadorImpositivo::cargarFactura(const string serv, int num, float mon){
    Factura factura(serv, num, mon);
    facturas.push_back(factura);
}

ReciboDePago CalculadorImpositivo::calcularImpuesto(int facturaInicio, int facturaFin){
    float total = 0;
    float montoVariable = 0;
    for(const Factura& f : facturas){
        if(f.getNumero() >= facturaInicio && f.getNumero() <= facturaFin){
            total += f.getMonto();
            montoVariable += categoria->calcularMontoVariable(f);
        }
    }

    float montoTotal = total + montoFijo + montoVariable;
    return ReciboDePago(nombre, montoTotal, montoFijo, montoVariable, facturaInicio, facturaFin);
}
