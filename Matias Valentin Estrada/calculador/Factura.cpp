#include "Factura.h"

/// Constructor y Destructor ///
Factura::Factura(const string det, int num, int mon){
    detalle = det;
    numero = num;
    monto = mon;
}

Factura::~Factura(){}


/// Getters ///
string Factura::getDetalle(void) const{
    return detalle;
}

int Factura::getNumero(void) const{
    return numero;
}

float Factura::getMonto(void) const{
    return monto;
}
