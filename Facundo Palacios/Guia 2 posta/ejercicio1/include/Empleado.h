#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Fecha.h"
#include <string>

class Empleado
{
    public:
        Empleado(const std::string& nombres, const std::string& apellidos, const Fecha& fc, const Fecha& fn);
        virtual ~Empleado();

        void imprimir() const;

    protected:

    private:
         std::string nombres;
    std::string apellidos;
        Fecha fechacontratacion;
        Fecha fechanacimiento;
};

#endif // EMPLEADO_H
