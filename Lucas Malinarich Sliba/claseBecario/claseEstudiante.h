#ifndef CLASEESTUDIANTE_H_INCLUDED
#define CLASEESTUDIANTE_H_INCLUDED

#include "clasePersona.h"

class Estudiante: public Persona{
protected:
    std::string carrera;
    Fecha ingCarrera;
    unsigned int materias;
    float promedio;
public:
    Estudiante(std::string carrera="\0",
        const Fecha& ingCarrera=Fecha(0, 0, 0),
        unsigned int materias=0,
        float promedio=0);
    virtual ~Estudiante();
    void setCarrera(std::string);
    void setIngCarrera(const Fecha&);
    void setMaterias(unsigned int);
    void setPromedio(float);
    std::string getCarrera()const;
    Fecha getIngCarrera()const;
    unsigned int getMaterias()const;
    float getPromedio()const;
};

#endif // CLASEESTUDIANTE_H_INCLUDED
