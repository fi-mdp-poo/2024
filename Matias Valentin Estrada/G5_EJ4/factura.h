#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <string>

using namespace std;

class Factura{
    private:
        int numero;
        string detalle;
        float monto;

    public:
        ///Constructor y Destructor ///
        Factura(int num, const string& det, float m);
        virtual ~Factura();

        /// Getters ///
        int getNumero() const;
        string getDetalle() const;
        float getMonto() const;
};

#endif
