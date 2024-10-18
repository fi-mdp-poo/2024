#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <iostream>

using namespace std;

class Factura
{
    public:
        Factura();
        virtual ~Factura();

        string Getservicio() { return servicio; }
        void Setservicio(string val) { servicio = val; }
        float Getmonto() { return monto; }
        void Setmonto(float val) { monto = val; }
        int Getnumero_fijo() { return numero_fijo; }
        void Setnumero_fijo(int val) { numero_fijo = val; }

    protected:

    private:
        string servicio;
        float monto;
        int numero_fijo;
};

#endif // FACTURA_H
