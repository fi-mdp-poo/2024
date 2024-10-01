#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include "Empleado.h"
using namespace std;

class Empresa
{
    public:
        Empresa();
        virtual ~Empresa();

        vector<Empleado*> Getempleados() { return empleados; }
        void Setempleados(vector<Empleado*> val) { empleados = val; }

        void agregarEmpleado(Empleado* e);
        float montoTotal() const;

    protected:

    private:
        vector <Empleado*> empleados;
};

#endif // EMPRESA_H
