#ifndef COMPLETO_H
#define COMPLETO_H

#include "CalculadorImpositivo.h"

class Completo : public CalculadorImpositivo
{
    public:
        Completo(string nombre, string categoria, float montofijo=5);
        virtual ~Completo();

        RecibodePago calcularimpuesto(int, int);
        float montovariable(int, int);

    protected:

    private:
};

#endif // COMPLETO_H
