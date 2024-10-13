#ifndef CUENTAUNIVERSITARIA_H
#define CUENTAUNIVERSITARIA_H

#include "CajaAhorro.h"

class CuentaUniversitaria : public CajaAhorro
{
    public:
        CuentaUniversitaria(string nombre, float saldo=0.0);
        virtual ~CuentaUniversitaria();

        float Getextraida() { return extraida; }
        void Setextraida(float val) { extraida=val; }
         int Getdia() { return dia; }
        void Setdia(int val) { dia = val; }

        void extraer();

    protected:

    private:
        int dia;
        float extraida;
};

#endif // CUENTAUNIVERSITARIA_H
