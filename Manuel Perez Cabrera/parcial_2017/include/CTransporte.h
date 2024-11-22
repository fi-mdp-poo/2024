#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H
#include <string>
#include "CColor.h"

using namespace std;

class CTransporte
{
public:
    CTransporte(string Matricula = "Default", CColor = CColor(0));
   // CTransporte();
    virtual ~CTransporte();

    string GetMatricula()
    {
        return Matricula;
    }
    void SetMatricula(string val)
    {
        Matricula = val;
    }
    CColor& GetColor()
    {
        return Color;
    }
    void SetColor(CColor val)
    {
        Color = val;
    }

    virtual void imprimir(ostream& os);
    friend ostream& operator << (ostream&, CTransporte&);

protected:

private:
    string Matricula;
    CColor Color;
};

#endif // CTRANSPORTE_H
