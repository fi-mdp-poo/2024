#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Factura{
    private:
        string detalle;
        int numero;
        float monto;

    public:
        Factura(const string det, int num, int mon);
        virtual ~Factura();

        string getDetalle(void) const;
        int getNumero(void) const;
        float getMonto(void) const;
};


#endif // FACTURA_H_INCLUDED
