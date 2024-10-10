#ifndef CLASEEMPRESA_H_INCLUDED
#define CLASEEMPRESA_H_INCLUDED

#include "claseEmpleado.h"
#include <vector>

using namespace std;

class Empresa{
private:
    vector <Empleado*> empleados;
public:
    //sobrecargar el operador <<
    Empresa();
    virtual ~Empresa();

    void setEmpleados(vector<Empleado*> val) { empleados = val; }
    vector<Empleado*> getEmpleados() const { return empleados; }
    //ordenar el vector alfabticamente
    void agregarEmpleado(Empleado* trabajador);
    Empleado* despedirEmpleado(string nombre);
    double montoTotal(const Fecha&) const;

};
#endif // CLASEEMPRESA_H_INCLUDED
