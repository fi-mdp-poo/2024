#ifndef CLASEPERSONA_H_INCLUDED
#define CLASEPERSONA_H_INCLUDED

#include "claseFecha.h"
#include <iostream>

class Persona{
protected:
    std::string nombre;
    unsigned int documento;
    Fecha nacimiento;
public:
    friend std::ostream& operator<<(std::ostream&, Persona&);
    Persona(std::string nom="\0",
        unsigned doc=0,
        const Fecha &nacimiento=Fecha(0, 0, 0));
    virtual ~Persona();
    void setNombre(std::string);
    void setDocumeno(unsigned int);
    void setNacimiento(const Fecha&);
    std::string getNombre()const;
    unsigned int getDocumento()const;
    Fecha getNacimieno()const;
};

#endif // CLASEPERSONA_H_INCLUDED
