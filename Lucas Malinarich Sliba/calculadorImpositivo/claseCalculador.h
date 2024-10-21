#ifndef CLASECALCULADOR_H_INCLUDED
#define CLASECALCULADOR_H_INCLUDED

#include "claseContribuyente.h"
#include "claseRecibo.h"

class CalculadorImpositivo{
private:
    Contribuyente* contribuyente;
public:
    CalculadorImpositivo();
    virtual ~CalculadorImpositivo();
    void inicializar(std::string nombre, int tipoDato);
    void cargarFactura(std::string servicio, int numFactura, double monto);
//    Factura* eliminarFactura(std::string servicio); también podemos usar el num de factura
    ReciboDePago calcularImpuesto(int numFac1, int numFac2);
};

#endif // CLASECALCULADOR_H_INCLUDED
