#ifndef RECIBODEPAGO_H_INCLUDED
#define RECIBODEPAGO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ReciboDePago{
    private:
        string NombreDelContribuyente;
        float MontoTotal;
        float MontoFijo;
        float MontoVariable;
        int PrimeraFacturaConsiderada;
        int UltimaFacturaConsiderada;

    public:
        ReciboDePago(const string nombre, float total, float fijo, float variable, int inicio, int fin);
        virtual ~ReciboDePago();

        /// Getters ///
        string nombreDelContribuyente() const;
        float montoTotal() const;
        float montoFijo() const;
        float montoVariable() const;
        int primeraFacturaConsiderada() const;
        int ultimaFacturaConsiderada() const;

        void printRecibo(); // Imprime toda la informacion del recibo
};

#endif // RECIBODEPAGO_H_INCLUDED
