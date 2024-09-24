#ifndef BECARIO_H
#define BECARIO_H

#include "empleado.h"
#include "estudiante.h"

class becario : public empleado, public estudiante
{
    public:
        becario();
        becario(string, unsigned, fecha,
                string, fecha, int, float,
                string, fecha, float,
                string, int, string, string);
        ~becario();
        string stGetTipo();
        void vSetTipo(string);
        int iGetDuracion();
        void vSetDuracion(int);
        string stGetLaboratorio();
        void vSetLaboratorio(string);
        string stGetDirector();
        void vSetDirector(string);
        friend ostream& operator << (ostream&, becario&);
    protected:
    private:
        string stTipo;
        int iDuracion;
        string stLaboratorio;
        string stDirector;
};

void vPrint(becario &);

#endif // BECARIO_H
