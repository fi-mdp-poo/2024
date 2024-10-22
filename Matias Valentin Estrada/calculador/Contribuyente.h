#ifndef CONTRIBUYENTE_H_INCLUDED
#define CONTRIBUYENTE_H_INCLUDED

#include <iostream>
#include <string>
#include "Factura.h"

using namespace std;

class Contribuyente{
    public:
        Contribuyente();
        virtual ~Contribuyente();

        virtual float calcularMontoVariable(const Factura& factura) const = 0;
};

class Limitado : public Contribuyente{
    public:
        Limitado();
        virtual ~Limitado();

        float calcularMontoVariable(const Factura& factura) const override;
};

class Completo : public Contribuyente{
    public:
        Completo();
        virtual ~Completo();

        float calcularMontoVariable(const Factura& factura) const override;
};

class Extendido : public Completo{
    public:
        Extendido();
        virtual ~Extendido();

        float calcularMontoVariable(const Factura& factura) const override;
};
#endif // CONTRIBUYENTE_H_INCLUDED
