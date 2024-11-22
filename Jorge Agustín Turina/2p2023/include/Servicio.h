#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
using namespace std;
#include "Fecha.h"
class Servicio
{
    public:
        Servicio();
        virtual ~Servicio();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string Getapellido() { return apellido; }
        void Setapellido(string val) { apellido = val; }
        Fecha Getfecha_ingreso() { return fecha_ingreso; }
        void Setfecha_ingreso(Fecha val) { fecha_ingreso = val; }
        Fecha Getfecha_servicio() { return fecha_servicio; }
        void Setfecha_servicio(Fecha val) { fecha_servicio = val; }
        string Getcliente() { return cliente; }
        void Setcliente(string val) { cliente = val; }
        int Getcuit() { return cuit; }
        void Setcuit(int val) { cuit = val; }

    protected:

    private:
        int id;
        string nombre;
        string apellido;
        Fecha fecha_ingreso;
        Fecha fecha_servicio;
        string cliente;
        int cuit;
};

#endif // SERVICIO_H
