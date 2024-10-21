#include "claseRecibo.h"

using namespace std;

ReciboDePago::ReciboDePago(string nombre, double mFijo, double mVariable, int primera, int ultima){
    nombreContribuyente=nombre;
    montoFijo=mFijo;
    montoVariable=mVariable;
    primFactura=primera;
    ultFactura=ultima;
}

ReciboDePago::~ReciboDePago(){  }

string ReciboDePago::nombreDelContribuyente()const{ return nombreContribuyente; }
double ReciboDePago::getMontoFijo()const{ return montoFijo; }
double ReciboDePago::getMontoVariable()const{ return montoVariable; }
double ReciboDePago::getMontoTotal()const{
    return getMontoFijo()+getMontoVariable();
}

int ReciboDePago::primeraFacturaConsiderada()const{ return primFactura; }
int ReciboDePago::ultimaFacturaConsiderada()const{ return ultFactura; }
