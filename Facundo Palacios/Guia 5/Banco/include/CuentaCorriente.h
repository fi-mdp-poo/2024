#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "CuentaBancaria.h"

class CuentaCorriente : public CuentaBancaria
{
    public:
        CuentaCorriente(string nombre, float saldo=0.0, float tope=0.0);
        virtual ~CuentaCorriente();

        float Gettope() { return tope; }
        void Settope(float val) { tope = val; }
        float Getuso() { return uso; }
        void Setuso(float val) { uso = val; }

        void extraer();

    protected:

    private:
        float tope;
        float uso;
};

#endif // CUENTACORRIENTE_H
