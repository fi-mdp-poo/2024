#ifndef PLANTATEMPORARIA_H
#define PLANTATEMPORARIA_H

#include "Empleado.h"

class PlantaTemporaria : public Empleado
{
    public:
        PlantaTemporaria(string n, int horas, int hijos, bool casado);
        virtual ~PlantaTemporaria();

        float calcularSalario() const override;

    protected:

    private:
};

#endif // PLANTATEMPORARIA_H
