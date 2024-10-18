#include "contribuyente.h"

/*** CLASE CONTRIBUYENTE ***/

/// Constructor y Destructor ///
Contribuyente::Contribuyente(const string& nom){
    nombre = nom;
}

Contribuyente::~Contribuyente(){

}

/// Metodos ///
void Contribuyente::agregarFactura(const Factura& factura){
    facturas.push_back(factura);
}

/// Getters ///
string Contribuyente::getNombre() const{
    return nombre;
}

const vector<Factura>& Contribuyente::getFacturas() const{
    return facturas;
}


/*** CLASE LIMITADO ***/

///Constructor y Destructor ///
Limitado::Limitado(const string& name) : Contribuyente(name){}

Limitado::~Limitado(){}

/// Metodos ///
float Limitado::calcularMontoVariable(const Factura& factura) const{
    return factura.getMonto() * 0.005;
}


/*** CLASE COMPLETO ***/

///Constructor y Destructor ///
Completo::Completo(const string& name) : Contribuyente(name){}

Completo::~Completo(){}

/// Metodos ///
float Completo::calcularMontoVariable(const Factura& factura) const{
    return (factura.getMonto() > 5000) ? factura.getMonto() * 0.5 : 0;
}


/*** CLASE EXTENDIDO ***/

///Constructor y Destructor ///
Extendido::Extendido(const string& name) : Contribuyente(name){}

Extendido::~Extendido(){}

/// Metodos ///
float Extendido::calcularMontoVariable(const Factura& factura) const{
    if(factura.getMonto() > 5000){
        return factura.getMonto() * 0.5 + 10;
    }
    return 0;
}
