#ifndef PLANTAPERMANENTE_H
#define PLANTAPERMANENTE_H

#include "Empleado.h"

class PlantaPermanente : public Empleado
{
    public:
        PlantaPermanente(string n, int horas, int hijos, bool casado, int antiguedad);
        virtual ~PlantaPermanente();

        int Getantiguedad() const { return antiguedad; }
        void Setantiguedad(int val) { antiguedad = val; }

        float calcularSalario() const override;

    protected:

    private:
        int antiguedad;
};

#endif // PLANTAPERMANENTE_H
