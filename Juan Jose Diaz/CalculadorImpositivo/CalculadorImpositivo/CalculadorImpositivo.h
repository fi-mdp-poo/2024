#ifndef CALCULADORIMPOSITIVO_H
#define CALCULADORIMPOSITIVO_H

#include <list>
#include "ContribuyenteFactory/ContribuyenteFactory.h"
#include "./Contribuyente/Contribuyente.h"
#include "./Factura/Factura.h"
#include "./ReciboDePago/ReciboDePago.h"

using namespace std;

class CalculadorImpositivo {
    private:
        Contribuyente* _contribuyente{};
        list<Factura*> _facturas;
        const double _montoFijo = 5.0;

    public:
        CalculadorImpositivo();

        void inicializar(const string& nombreContribuyente, CategoriaEnum categoria);

        void agregarFactura(const string& detalle, int numeroFactura, double monto);

        ReciboDePago calcularImpuesto(int numFacturaInicio, int numFacturaFin) const;

        ~CalculadorImpositivo();
};

#endif //CALCULADORIMPOSITIVO_H
