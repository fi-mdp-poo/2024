#ifndef C_TRABAJADOR_H
#define C_TRABAJADOR_H

#include "C_Fecha.h"
#include <iostream>
#include <string>
using namespace std;

class C_Trabajador
{
    public:
        ///Constructores y Destructores
        C_Trabajador();
        virtual ~C_Trabajador();

        ///Getters y Setters
        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        C_Fecha Getfecha_ingreso() { return fecha_ingreso; }
        void Setfecha_ingreso(int d, int m, int a);
        int Getcodigo() { return codigo; }
        void Setcodigo(int val) { codigo = val; }

        ///Sobrecarga
        friend ostream& operator <<(ostream& os, C_Trabajador& actual);

    protected:

    private:
        string nombre;
        C_Fecha fecha_ingreso;
        int codigo;
};

#endif // C_TRABAJADOR_H
