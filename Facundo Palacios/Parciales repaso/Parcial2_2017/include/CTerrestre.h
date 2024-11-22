#ifndef CTERRESTRE_H
#define CTERRESTRE_H

#include "CTransporte.h"

class CTerrestre : public CTransporte
{
    public:
       // CTerrestre();
        CTerrestre(string mat="default", string marc="Renault", CColor col=CColor(0), int rue=4, float vel=0.0);
        virtual ~CTerrestre();

        string GetMarca() { return Marca; }
        void SetMarca(string val) { Marca = val; }
        int GetRuedas() { return Ruedas; }
        void SetRuedas(int val) { Ruedas = val; }
        float GetVelocidad() { return Velocidad; }
        void SetVelocidad(float val) { Velocidad = val; }

        friend ostream& operator<< (ostream& co, CTerrestre &cmp);
        void imprimir(ostream& co)  override;

    protected:

    private:
        string Marca;
        int Ruedas;
        float Velocidad;
};

#endif // CTERRESTRE_H
