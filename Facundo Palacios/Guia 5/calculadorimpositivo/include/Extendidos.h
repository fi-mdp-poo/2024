#ifndef EXTENDIDOS_H
#define EXTENDIDOS_H

#include "CalculadorImpositivo.h"

class Extendidos : public CalculadorImpositivo
{
    public:
        Extendidos(string nombre, string categoria, float montofijo=5);
        virtual ~Extendidos();

        RecibodePago calcularimpuesto(int, int);
        float montovariable(int, int);


    protected:

    private:
};

#endif // EXTENDIDOS_H
