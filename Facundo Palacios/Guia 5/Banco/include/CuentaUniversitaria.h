#ifndef CUENTAUNIVERSITARIA_H
#define CUENTAUNIVERSITARIA_H

#include "CajaAhorro.h"

class CuentaUniversitaria : public CajaAhorro
{
    public:
        CuentaUniversitaria(string nombre, float saldo=0.0);
        virtual ~CuentaUniversitaria();

        void extraer();

    protected:

    private:
};

#endif // CUENTAUNIVERSITARIA_H
