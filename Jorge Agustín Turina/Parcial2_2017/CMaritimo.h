#ifndef CMARITIMO_H
#define CMARITIMO_H

#include "CTransporte.h"

using namespace std;

class CMaritimo : public CTransporte
{
    public:
        CMaritimo();
        CMaritimo(string, string, int, int);
        virtual ~CMaritimo();

        int GetPasajeros() { return Pasajeros; }
        void SetPasajeros(int val) { Pasajeros = val; }
        string GetNombre() { return Nombre; }
        void SetNombre(string val) { Nombre = val; }

    protected:

    private:
        int Pasajeros;
        string Nombre;
};

#endif // CMARITIMO_H
