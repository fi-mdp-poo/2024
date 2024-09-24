#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"

class empleado : public persona
{
    public:
        empleado();
        empleado(string, unsigned, fecha, string, fecha, float);
        empleado(string, unsigned, int, int, int, string, int, int, int, float);
        ~empleado();
        string stGetCategoria();
        void vSetCategoria(string);
        void vSetIngreso(fecha);
        void vSetIngreso(int, int, int);
        fecha fechaGetIngreso();
        float fGetSueldo();
        void vSetSueldo(float);
        friend ostream& operator << (ostream&, empleado&);
    private:
    protected:
        string stCategoria;
        fecha fechaIngreso;
        float fSueldo;
};

void vPrint(empleado &);

#endif // EMPLEADO_H
