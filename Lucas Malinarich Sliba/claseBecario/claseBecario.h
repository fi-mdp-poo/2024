#ifndef CLASEBECARIO_H_INCLUDED
#define CLASEBECARIO_H_INCLUDED

#include "claseEstudiante.h"
#include "claseEmpleado.h"

class Becario: public Estudiante, public Empleado{
private:
    std::string tipo, laboratorio, director;
    unsigned int duracion;
public:
    Becario(std::string tipo="\0",
        std::string laboratorio="\0",
        std::string director="\0",
        unsigned int duracion=0);
    virtual ~Becario();
    void setTipo(std::string);
    void setLaboratorio(std::string);
    void setDirector(std::string);
    void setDuracion(unsigned int);
    std::string getTipo()const;
    std::string getLaboratorio()const;
    std::string getDirector()const;
    unsigned int getDuracion()const;
};

#endif // CLASEBECARIO_H_INCLUDED
