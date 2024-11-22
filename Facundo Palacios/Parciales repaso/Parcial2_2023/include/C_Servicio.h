#ifndef C_SERVICIO_H
#define C_SERVICIO_H

#include <iostream>
#include "C_Trabajador.h"
#include "C_Cliente.h"
#include "C_Fecha.h"

using namespace std;

class C_Servicio
{
    public:
        ///Constructores y Destructores
        C_Servicio(string nombre_t, int d_i, int m_i, int a_i, int id, int d_s, int m_s, int a_s, string nombre_c, int cuit);
        virtual ~C_Servicio();

        ///Getters y Setters
        C_Trabajador GetTrabajador() { return Trabajador; }
        void SetTrabajador(C_Trabajador val) { Trabajador = val; }
        C_Fecha Getinicio_servicio() { return inicio_servicio; }
        void Setinicio_servicio(C_Fecha val) { inicio_servicio = val; }
        C_Cliente Getcliente() { return cliente; }
        void Setcliente(C_Cliente val) { cliente = val; }

        ///Sobrecarga
        friend ostream& operator<< (ostream&, C_Servicio&);

        ///Metodos
        virtual float costoMaterial()=0;
        virtual float costoManoObra()=0;
        virtual float costoTotal()=0;
        virtual void detalleServicio()=0;
        virtual void vImprimir(ostream& os=cout)=0;

    protected:

    private:
        C_Trabajador Trabajador;
        C_Fecha inicio_servicio;
        C_Cliente cliente;
};

#endif // C_SERVICIO_H
