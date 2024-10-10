#include "headers/claseEstudiante.h"

Estudiante::Estudiante(std::string car, const Fecha& ingCar, unsigned mat, float prom){
    setCarrera(car);
    setIngCarrera(ingCar);
    setMaterias(mat);
    setPromedio(prom);
}
Estudiante::~Estudiante(){  }
void Estudiante::setCarrera(std::string car){ carrera=car; }
void Estudiante::setIngCarrera(const Fecha &ingCar){ ingCarrera=ingCar; }
void Estudiante::setMaterias(unsigned int mat){ materias=mat; }
void Estudiante::setPromedio(float prom){ promedio=prom; }

std::string Estudiante::getCarrera()const{ return carrera; }
Fecha Estudiante::getIngCarrera()const{ return ingCarrera; }
unsigned int Estudiante::getMaterias()const{ return materias; }
float Estudiante::getPromedio()const{ return promedio; }
