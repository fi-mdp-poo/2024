#include "claseCuenta.h"

cCorriente::cCorriente(string nombre, double monto, double limite){
    setTitular(nombre);
    setSaldo(monto);
    setTope(limite);
}

cCorriente::~cCorriente(){  }

void cCorriente::extraer(double monto){
    if(getSaldo()-monto<getTope())
        setSaldo(getSaldo()-monto);
    else
        cout<<"No es posible realizar la extracción\n";
}

void cCorriente::setTope(double limite){ tope=limite; }
double cCorriente::getTope() const{ return tope; }
