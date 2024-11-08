#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Persona {
    public:
    string _nombre;
    string _direccion;
    string _telefono;

    Persona();

    Persona(const string& nombre, const string& direccion, const string& telefono);

    friend ostream& operator<<(ostream& os, const Persona& p);

    friend istream& operator>>(istream& is, Persona& p);
};


#endif //PERSONA_H
