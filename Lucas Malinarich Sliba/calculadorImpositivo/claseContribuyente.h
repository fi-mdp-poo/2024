#ifndef CLASECONTRIBUYENTE_H_INCLUDED
#define CLASECONTRIBUYENTE_H_INCLUDED

#include "claseFactura.h"
#include <vector>
#define IMPUESTOFIJO 5
#define IMPUESTOEXTENDIDO 5

enum{
    LIMITADO=1, COMPLETO=2, EXTENDIDO=3
};

class Contribuyente{
protected:
    std::string nombre;
    std::vector <Factura*> facturas;
public:
    Contribuyente(std::string nombre="\0");
    virtual ~Contribuyente();
    double calcularMontoFijo(int numFac1, int numFac2);
    virtual double calcularMontoVariable(int numFac1, int numFac2)=0;
    void agregarFactura(Factura*);
    Factura* eliminarFactura(int numFactura);
//    Factura* getFactura(int numFactura)const;
    std::string getNombre()const;
};

class Limitado: public Contribuyente{
public:
    Limitado(std::string nombre="\0");
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

class Completo: public Contribuyente{
public:
    Completo(std::string nombre="\0");
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

class Extendido: public Completo{
public:
    Extendido(std::string nombre="\0");
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

#endif // CLASECONTRIBUYENTE_H_INCLUDED
