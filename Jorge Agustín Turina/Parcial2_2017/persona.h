#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string>
#include "CFecha.h"

using namespace std;

class persona
{
    private:
        string nombre;
        int documento;
        CFecha nacimiento;

    public:
        ///Constructores y Destructores
        persona(string = "Pedro", int = 12345678, CFecha = CFecha());
        virtual ~persona();

        ///Getters
        string GetNombre();
        int GetDocument();
        CFecha GetNacimiento();

        ///Sobrecarga <<
        friend ostream& operator<< (ostream& co, persona &cmp);

};

#endif // PERSONA_H_INCLUDED
