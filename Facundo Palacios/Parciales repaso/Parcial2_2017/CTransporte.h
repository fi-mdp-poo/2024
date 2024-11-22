#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H

#include <string>
#include <iostream>
#include "CColor.h"

using namespace std;

class CTransporte
{
public:
    //CTransporte();
    CTransporte(string mat="default", CColor col=CColor(0));
    virtual ~CTransporte();

    CColor& GetColor()
    {
        return Color;
    }
    void SetColor(CColor val)
    {
        Color = val;
    }
    string GetMatricula()
    {
        return Matricula;
    }
    void SetMatricula(string val)
    {
        Matricula = val;
    }

    virtual void imprimir(ostream& os)
    {
        os << "Transporte genérico";
    }

    friend ostream& operator<< (ostream& co, CTransporte &cmp);

protected:

private:
    CColor Color;
    string Matricula;
};

#endif // CTRANSPORTE_H
