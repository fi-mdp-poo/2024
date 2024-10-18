#include "factura.h"

/// Constructor y Destructor ///

Factura::Factura(int num, const string& det, float m){
    numero = num;
    detalle = det;
    monto = m;
}

Factura::~Factura(){

}

/// Getters ///

int Factura::getNumero()const{
    return numero;
}

string Factura::getDetalle()const{
    return detalle;
}

float Factura::getMonto()const{
    return monto;
}
