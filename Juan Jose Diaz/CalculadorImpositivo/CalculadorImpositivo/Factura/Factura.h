#ifndef FACTURA_H
#define FACTURA_H

#include <ostream>
using namespace std;

class Factura {
    private:
        string _detalle;
        int _numeroFactura;
        double _monto;

    public:
        Factura(const string& detalle, int numeroFactura, double monto);

        int getNumeroFactura() const;

        double getMonto() const;

        /**
         * Cuando el destructor no hace nada particular, asignar `default` permite al compilador optimizar la
         * destruccion de objetos de la clase, además indica explicitamente que no hay liberacion manuales de recursos.
         */
        ~Factura();
};

#endif //FACTURA_H
