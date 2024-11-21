#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include "CFecha.h"
#include <iostream>

using namespace std;

class persona
{
    private:
        string nombre;
        int documento;
        CFecha nacimiento;

    public:
        persona(string = "Pedro", int = 12345678, CFecha = CFecha());
        virtual ~persona();

        string GetNombre();
        int GetDocument();
        CFecha GetNacimiento();

        friend ostream& operator<< (ostream& co, persona &cmp);

};

#endif // PERSONA_H
