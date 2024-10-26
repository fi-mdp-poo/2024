#ifndef RECIBODEPAGO_H
#define RECIBODEPAGO_H

#include <iostream>
using namespace std;

class ReciboDePago {
    private:
        string _nombreContribuyente;
        double _montoTotal;
        double _montoFijo;
        double _montoVariable;
        int _primeraFactura;
        int _ultimaFactura;

    public:
        ReciboDePago(
            const string& nombreContribuyente,
            double montoTotal,
            double montoFijo,
            double montoVariable,
            int primeraFactura,
            int ultimaFactura
        );

        string getNombreDelContribuyente() const ;

        double getMontoTotal() const;

        double getMontoFijo() const;

        double getMontoVariable() const;

        int getPrimeraFacturaConsiderada() const;

        int getUltimaFacturaConsiderada() const;
};

#endif //RECIBODEPAGO_H
