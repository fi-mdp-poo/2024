#ifndef CAJAAHORRO_H
#define CAJAAHORRO_H

#include "CuentaBancaria.h"

class CajaAhorro : public CuentaBancaria
{
    public:
        CajaAhorro(string nombre, float saldo=0.0, int extracciones=0);
        virtual ~CajaAhorro();

        int Getextracciones() { return extracciones; }
        void Setextracciones(int val) { extracciones = val; }
        int Getrealizadas() { return realizadas; }
        void Setrealizadas(int val) { realizadas = val; }

        void extraer();


    protected:

    private:
        int extracciones;
        int realizadas;
};

#endif // CAJAAHORRO_H
