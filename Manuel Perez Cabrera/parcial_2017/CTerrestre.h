#ifndef CTERRESTRE_H
#define CTERRESTRE_H
#include "CTransporte.h"

class CTerrestre : public CTransporte
{
    public:
        CTerrestre();
        virtual ~CTerrestre();

        string GetMarca() { return Marca; }
        void SetMarca(string val) { Marca = val; }
        float GetVelocidad() { return Velocidad; }
        void SetVelocidad(float val) { Velocidad = val; }
        int GetRuedas() { return Ruedas; }
        void SetRuedas(int val) { Ruedas = val; }

        friend ostream& operator << (ostream&, CTerrestre&);
        void imprimir(ostream& os);

    protected:

    private:
        string Marca;
        float Velocidad;
        int Ruedas;
};

#endif // CTERRESTRE_H
