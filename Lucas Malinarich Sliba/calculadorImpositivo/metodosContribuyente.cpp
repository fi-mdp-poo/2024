#include "claseContribuyente.h"

using namespace std;

Contribuyente::Contribuyente(string nombreDado){
    nombre=nombreDado;
}

Contribuyente::~Contribuyente(){
    while(!facturas.empty()){
        delete eliminarFactura(facturas[0]->getNumFactura());
    }
}

void Contribuyente::agregarFactura(Factura* factura){
    facturas.push_back(factura);
}

Factura* Contribuyente::eliminarFactura(int numFac){
    Factura* aux=NULL;
    int longitud=facturas.size(), i=0;
    bool encontrado=false;
    while(!encontrado&&i<longitud){
        aux=facturas[i];
        encontrado=(aux->getNumFactura()==numFac);
        if(!encontrado)
            i++;
    }
    if(encontrado){
        facturas.erase(facturas.begin()+i);
        return aux;
    }
    return NULL;
}

double Contribuyente::calcularMontoFijo(int numFac1, int numFac2){
    int longitud=facturas.size(), cantFacturas=0, i=0;
    bool flag=false;
    while(i<longitud){
        if(numFac1==facturas[i]->getNumFactura())
            flag=true;
        if(flag){
            cantFacturas++;
        }
        if(numFac2==facturas[i]->getNumFactura())
            flag=false;
        i++;
    }
    return cantFacturas*IMPUESTOFIJO;
}

string Contribuyente::getNombre()const{ return nombre; }

Limitado::Limitado(string nombreDado){
    nombre=nombreDado;
}

double Limitado::calcularMontoVariable(int numFac1, int numFac2){
    int longitud=facturas.size(), i=0;
    double impuesto=0.0;
    bool flag=false;
    while(i<longitud){
        if(numFac1==facturas[i]->getNumFactura())
            flag=true;
        if(flag){
            impuesto+=(facturas[i]->getMonto()*.005);
        }
        if(numFac2==facturas[i]->getNumFactura())
            flag=false;
        i++;
    }
    return impuesto;
}

Completo::Completo(string nombreDado){
    nombre=nombreDado;
}

double Completo::calcularMontoVariable(int numFac1, int numFac2){
    int longitud=facturas.size(), i=0;
    double impuesto=0.0;
    bool flag=false;
    while(i<longitud){
        if(numFac1==facturas[i]->getNumFactura())
            flag=true;
        if(flag&&facturas[i]->getMonto()>=5000){
            impuesto+=(facturas[i]->getMonto()*.5);
        }
        if(numFac2==facturas[i]->getNumFactura())
            flag=false;
        i++;
    }
    return impuesto;
}

Extendido::Extendido(string nombreDado){
    nombre=nombreDado;
}

double Extendido::calcularMontoVariable(int numFac1, int numFac2){
    int longitud=facturas.size(), i=0, cantFacturas;
    double impuesto=Completo::calcularMontoVariable(numFac1, numFac2);
    bool flag=false;
    while(i<longitud){
        if(numFac1==facturas[i]->getNumFactura())
            flag=true;
        if(flag){
            cantFacturas++;
        }
        if(numFac2==facturas[i]->getNumFactura())
            flag=false;
        i++;
    }
    return impuesto+(cantFacturas*IMPUESTOEXTENDIDO);
}
