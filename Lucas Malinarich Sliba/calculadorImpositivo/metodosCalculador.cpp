#include "claseCalculador.h"

using namespace std;

CalculadorImpositivo::CalculadorImpositivo(){  }
CalculadorImpositivo::~CalculadorImpositivo(){
    if(contribuyente)
        delete contribuyente;
}

void CalculadorImpositivo::inicializar(string nombre, int tipoDato){
    if(contribuyente)
        delete contribuyente;
    switch(tipoDato){
        case LIMITADO : contribuyente=new Limitado(nombre); break;
        case COMPLETO : contribuyente=new Completo(nombre); break;
        case EXTENDIDO : contribuyente=new Extendido(nombre); break;
    }
}

void CalculadorImpositivo::cargarFactura(string servicio, int numFactura, double monto){
    Factura* nuevaFactura=new Factura(servicio, numFactura, monto);
    contribuyente->agregarFactura(nuevaFactura);
}

ReciboDePago CalculadorImpositivo::calcularImpuesto(int numFac1, int numFac2){
    double montoFijo, montoVariable;
    montoFijo=contribuyente->calcularMontoFijo(numFac1, numFac2);
    montoVariable=contribuyente->calcularMontoVariable(numFac1, numFac2);
    ReciboDePago recibo(contribuyente->getNombre(), montoFijo, montoVariable, numFac1, numFac2);
    return recibo;
}
