#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H
#include <string>

using namespace std;

class CTransporte
{
public:
    CTransporte(string Matricula = "Default", int Color = 0);
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
    int GetColor()
    {
        return Color;
    }
    void SetColor(int val)
    {
        Color = val;
    }

protected:

private:
    string Matricula;
    int Color;
};

#endif // CTRANSPORTE_H
