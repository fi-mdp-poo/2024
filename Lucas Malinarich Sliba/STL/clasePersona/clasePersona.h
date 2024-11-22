#ifndef CLASEPERSONA_H_INCLUDED
#define CLASEPERSONA_H_INCLUDED

#include <iostream>

using namespace std;

class Persona{
    string nombre, apellido;
    int dni;
public:
    friend ostream& operator<<(ostream&, const Persona&);
    Persona(string nombre="\0", string apellido="\0", int dni=0);
    virtual ~Persona();
    string getNombre()const;
    string getApellido()const;
    int getDNI()const;
    bool operator==(const Persona&);
//    bool operator!=(const Persona&);
};

#endif // CLASEPERSONA_H_INCLUDED
