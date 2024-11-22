#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include <iostream>

using namespace std;

class Empleado{
    string nombre, apellido;
    unsigned int dni, antiguedad;
    double sueldo;
public:
    friend ostream& operator<<(ostream& Cout, const Empleado& valor);
    Empleado(string Nombre="\0", string Apellido="\0",
             unsigned int Dni=0, unsigned int Antiguedad=0,
             double Sueldo=0.0);
    virtual ~Empleado();
    string getNombre()const;
    string getApellido()const;
    unsigned int getDNI()const;
    unsigned int getAntiguedad()const;
    double getApellido()const;
    bool operator<(const Empleado&)const;
};

#endif // CLASEEMPLEADO_H_INCLUDED
