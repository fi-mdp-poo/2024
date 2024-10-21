#ifndef CLASERECIBO_H_INCLUDED
#define CLASERECIBO_H_INCLUDED

#include <iostream>

class ReciboDePago{
private:
    std::string nombreContribuyente;
    double montoFijo, montoVariable;
    int primFactura, ultFactura;
public:
    ReciboDePago(std::string nombre="\0", double montoFijo=0, double montoVariable=0, int primera=0, int ultima=0);
    virtual ~ReciboDePago();
    std::string nombreDelContribuyente()const;
    double getMontoFijo()const;
    double getMontoVariable()const;
    double getMontoTotal()const;
    int primeraFacturaConsiderada()const;
    int ultimaFacturaConsiderada()const;
};


#endif // CLASERECIBO_H_INCLUDED
