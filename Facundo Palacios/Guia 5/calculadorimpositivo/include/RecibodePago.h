#ifndef RECIBODEPAGO_H
#define RECIBODEPAGO_H

#include "Factura.h"
#include <string>
#include <iostream>

using namespace std;

class RecibodePago
{
    public:
        RecibodePago(string nombre, float monto_variable, float monto_fijo, Factura* primera, Factura* ultima);
        virtual ~RecibodePago();

        float Getmonto_total() { return monto_total; }
        void Setmonto_total(float val) { monto_total = val; }
        float Getmonto_variable() { return monto_variable; }
        void Setmonto_variable(float val) { monto_variable = val; }
        float Getmonto_fijo() { return monto_fijo; }
        void Setmonto_fijo(float val) { monto_fijo = val; }
        string GetnombreContribuyente() { return nombreContribuyente; }
        void SetnombreContribuyente(string val) { nombreContribuyente = val; }
        Factura* GetprimeraFacturaConsiderada() { return primeraFacturaConsiderada; }
        void SetprimeraFacturaConsiderada(Factura* val) { primeraFacturaConsiderada = val; }
        Factura* GetultimaFacturaConsiderada() { return ultimaFacturaConsiderada; }
        void SetultimaFacturaConsiderada(Factura* val) { ultimaFacturaConsiderada = val; }

    protected:

    private:
        float monto_total;
        float monto_variable;
        float monto_fijo;
        string nombreContribuyente;
        Factura* primeraFacturaConsiderada;
        Factura* ultimaFacturaConsiderada;
};

#endif // RECIBODEPAGO_H
