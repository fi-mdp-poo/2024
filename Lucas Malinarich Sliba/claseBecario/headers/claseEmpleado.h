#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "clasePersona.h"

class Empleado: public Persona{
protected:
    std::string categoria;
    Fecha ingTrabajo;
    float sueldo;
public:
    friend std::ostream& operator<<(std::ostream&, Empleado&);
    Empleado(std::string categoria="\0", const Fecha& ingTrabajo=Fecha(0, 0, 0), float sueldo=0);
    virtual ~Empleado();
    void setCategoria(std::string);
    void setIngTrabajo(const Fecha&);
    void setSueldo(float);
    std::string getCategoria()const;
    Fecha getIngTrabajo()const;
    float getSueldo()const;
};

#endif // CLASEEMPLEADO_H_INCLUDED
