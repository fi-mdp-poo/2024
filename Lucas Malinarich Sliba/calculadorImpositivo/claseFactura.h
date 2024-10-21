#ifndef CLASEFACTURA_H_INCLUDED
#define CLASEFACTURA_H_INCLUDED

#include <iostream>

class Factura{
private:
    std::string servicio;
    int numFactura;
    double monto;
public:
    Factura(std::string serv="\0", int numFac=0, double montoFac=0.0);
    virtual ~Factura();
    void setServicio(std::string);
    void setNumFactura(int);
    void setMonto(double);
    std::string getServicio()const;
    int getNumFactura()const;
    double getMonto()const;
};

#endif // CLASEFACTURA_H_INCLUDED
