#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "CuentaBancaria.h"
using namespace std;

class Banco
{
    public:
        Banco();
        virtual ~Banco();

        vector <CuentaBancaria*> Getcuentas() { return cuentas; }
        void Setcuentas(vector <CuentaBancaria*> val) { cuentas = val; }

        void agregarcuenta(CuentaBancaria* cuenta);
        float calcularactivo();

    protected:

    private:
        vector <CuentaBancaria*> cuentas;
};

#endif // BANCO_H
