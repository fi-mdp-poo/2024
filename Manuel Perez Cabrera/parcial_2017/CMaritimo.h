#ifndef CMARITIMO_H
#define CMARITIMO_H
#include "CTransporte.h"

#include <string>
using namespace std;

class CMaritimo : public CTransporte
{
    public:

        CMaritimo(string Matricula = "0000",string Nombre = "nombre",CColor = CColor(0),int Pasajeros = 0);  ///string matri,string nombr,int col,int pasaj
        virtual ~CMaritimo();

        int GetPasajeros() { return Pasajeros; }
        void SetPasajeros(int val) { Pasajeros = val; }
        string GetNombre() { return Nombre; }
        void SetNombre(string val) { Nombre = val; }

        friend ostream& operator << (ostream& os, CMaritimo& t);
        void imprimir(ostream& os);

    protected:

    private:
        int Pasajeros;
        string Nombre;
};

#endif // CMARITIMO_H
