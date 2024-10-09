#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <string>
#include <iostream>
using namespace std;

class CuentaBancaria
{
    public:
        CuentaBancaria(string nombre, float saldo=0.0);
        virtual ~CuentaBancaria();

        string Gettitular() { return titular; }
        void Settitular(string val) { titular = val; }
        float Getsaldo() const { return saldo; }
        void Setsaldo(float val) { saldo = val; }

        virtual void extraer()const=0;
        void depositar(float cantidad);

    protected:

    private:
        string titular;
        float saldo;
};

#endif // CUENTABANCARIA_H
