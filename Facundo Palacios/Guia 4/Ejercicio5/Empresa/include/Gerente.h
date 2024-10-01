#ifndef GERENTE_H
#define GERENTE_H

#include "PlantaPermanente.h"

class Gerente : public PlantaPermanente
{
    public:
        Gerente(string n, int horas, int hijos, bool casado, int antiguedad);
        virtual ~Gerente();

        float calcularSalario() const override;

    protected:

    private:
};

#endif // GERENTE_H
