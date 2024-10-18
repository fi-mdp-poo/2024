#ifndef RECIBO_H
#define RECIBO_H

#include <iostream>
#include <string>

using namespace std;

class ReciboDePago{
    private:
        string nombreContribuyente;
        float montoTotal;
        float montoFijo;
        float montoVariable;
        int primeraFactura;
        int ultimaFactura;

    public:
        /// Constructor y Destructor ///
        ReciboDePago(const string& nombre, float total, float fijo, float variable, int primera, int ultima);
        virtual ~ReciboDePago();

        /// Getters ///
        string nombreDelContribuyente() const;
        float montoTotalCalculado() const;
        float montoFijoCalculado() const;
        float montoVariableCalculado() const;
        int primeraFacturaConsiderada() const;
        int ultimaFacturaConsiderada() const;

        /// Metodos ///
        void printRecibo();
};

#endif
