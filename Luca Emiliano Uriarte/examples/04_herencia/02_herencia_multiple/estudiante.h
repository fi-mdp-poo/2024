#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"

class estudiante : public persona
{
    public:
        estudiante();
        estudiante(string, unsigned, fecha, string, fecha, int, float);
        ~estudiante();
        string stGetCarrera();
        void vSetCarrera(string);
        fecha fechaGetIngreso();
        void vSetIngreso(fecha);
        void vSetIngreso(int, int, int);
        int iGetMaterias();
        void vSetMaterias(int);
        float fGetPromedio();
        void vSetPromedio(float);
        friend ostream& operator << (ostream&, estudiante&);
    private:
    protected:
        string stCarrera;
        fecha fechaIngreso;
        int iMaterias;
        float fPromedio;
};

void vPrint(estudiante &);

#endif // ESTUDIANTE_H
