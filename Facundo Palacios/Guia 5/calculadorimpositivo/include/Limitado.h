#ifndef LIMITADO_H
#define LIMITADO_H

#include "CalculadorImpositivo.h"

class Limitado : public CalculadorImpositivo
{
    public:
        Limitado(string nombre, string categoria, float montofijo=5);
        virtual ~Limitado();

        RecibodePago calcularimpuesto(int, int);
        float montovariable(int, int);

    protected:

    private:
};

#endif // LIMITADO_H
