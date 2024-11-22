#ifndef CMARITIMO_H
#define CMARITIMO_H

#include "CTransporte.h"

using namespace std;

class CMaritimo : public CTransporte
{
    public:
        //CMaritimo();
        CMaritimo(string mat="default", string name="default", CColor col=CColor(0), int pas=0);
        virtual ~CMaritimo();

        int GetPasajeros() { return Pasajeros; }
        void SetPasajeros(int val) { Pasajeros = val; }
        string GetNombre() { return Nombre; }
        void SetNombre(string val) { Nombre = val; }

        void imprimir(ostream& co) override;


        friend ostream& operator<< (ostream& co, CMaritimo &cmp);

    protected:

    private:
        int Pasajeros;
        string Nombre;
};

#endif // CMARITIMO_H
