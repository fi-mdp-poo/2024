#include "claseFactura.h"

using namespace std;

Factura::Factura(string serv, int numFac, double montoFac){
    setServicio(serv);
    setNumFactura(numFac);
    setMonto(montoFac);
}

Factura::~Factura(){  }

void Factura::setServicio(string serv){ servicio=serv; }
void Factura::setNumFactura(int numFac){ numFactura=numFac; }
void Factura::setMonto(double mont){ monto=mont; }

string Factura::getServicio()const{ return servicio; }
int Factura::getNumFactura()const{ return numFactura; }
double Factura::getMonto()const{ return monto; }
