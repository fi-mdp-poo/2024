#include "ReciboDePago.h"

/// Constructor y Destructor ///
ReciboDePago::ReciboDePago(const string nombre, float total, float fijo, float variable, int inicio, int fin){
    NombreDelContribuyente = nombre;
    MontoTotal = total;
    MontoFijo = fijo;
    MontoVariable = variable;
    PrimeraFacturaConsiderada = inicio;
    UltimaFacturaConsiderada = fin;
}

ReciboDePago::~ReciboDePago(){}

/// Metodo ///
void ReciboDePago::printRecibo(){
    cout << "Nombre del contribuyente: " << nombreDelContribuyente() << endl;
    cout << "Monto total: " << montoTotal() << endl;
    cout << "Monto fijo: " << montoFijo() << endl;
    cout << "Monto variable: " << montoVariable() << endl;
    cout << "Primera factura considerada: " << primeraFacturaConsiderada() << endl;
    cout << "Ultima factura considerada: " << ultimaFacturaConsiderada() << endl;
}


/// Getters ///
string ReciboDePago::nombreDelContribuyente() const{
    return NombreDelContribuyente;
}

float ReciboDePago::montoTotal() const{
    return MontoTotal;
}

float ReciboDePago::montoFijo() const{
    return MontoFijo;
}

float ReciboDePago::montoVariable() const{
    return MontoVariable;
}

int ReciboDePago::primeraFacturaConsiderada() const{
    return PrimeraFacturaConsiderada;
}

int ReciboDePago::ultimaFacturaConsiderada() const{
    return UltimaFacturaConsiderada;
}
