#ifndef CALCULADORIMPOSITIVO_H_INCLUDED
#define CALCULADORIMPOSITIVO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Factura.h"
#include "ReciboDePago.h"
#include "Contribuyente.h"

enum categ{LIMITADO, COMPLETO, EXTENDIDO};

using namespace std;

class CalculadorImpositivo{
    private:
        string nombre;
        Contribuyente* categoria;
        vector <Factura> facturas;
        float montoFijo = 5.0;

    public:
        CalculadorImpositivo();
        virtual ~CalculadorImpositivo();

        void inicializar(const string name, const categ cat);
        void cargarFactura(const string name, int num, float monto);
        ReciboDePago calcularImpuesto(int facturaInicio, int facturaFin);
};

#endif // CALCULADORIMPOSITIVO_H_INCLUDED
