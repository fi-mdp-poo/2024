#include "recibo.h"

/// Constructor y Destructor ///
ReciboDePago::ReciboDePago(const string& name, float total, float fijo, float variable, int primera, int ultima){
    nombreContribuyente = name;
    montoTotal = total;
    montoFijo = fijo;
    montoVariable = variable;
    primeraFactura = primera;
    ultimaFactura = ultima;
}

ReciboDePago::~ReciboDePago(){}

/// Metodos ///

void ReciboDePago::printRecibo(){
    cout << "Contribuyente: " << nombreDelContribuyente() << endl;
    cout << "Monto total: " << montoTotalCalculado() << endl;
    cout << "Monto fijo: " << montoFijoCalculado() << endl;
    cout << "Monto variable: " << montoVariableCalculado() << endl;
    cout << "Primera factura considerada: " << primeraFacturaConsiderada() << endl;
    cout << "Ultima factura considerada: " << ultimaFacturaConsiderada() << endl;
}

/// Getters ///
string ReciboDePago::nombreDelContribuyente() const{
    return nombreContribuyente;
}

float ReciboDePago::montoTotalCalculado() const{
    return montoTotal;
}

float ReciboDePago::montoFijoCalculado() const{
    return montoFijo;
}

float ReciboDePago::montoVariableCalculado() const{
    return montoVariable;
}

int ReciboDePago::primeraFacturaConsiderada() const{
    return primeraFactura;
}

int ReciboDePago::ultimaFacturaConsiderada() const{
    return ultimaFactura;
}
