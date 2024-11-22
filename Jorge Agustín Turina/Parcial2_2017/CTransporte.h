#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H

#include <string>
#include <iostream>

using namespace std;

class CTransporte
{
    public:
        CTransporte();
        CTransporte(string, int);
        virtual ~CTransporte();

        int GetColor() { return Color; }
        void SetColor(int val) { Color = val; }
        string GetMatricula() { return Matricula; }
        void SetMatricula(string val) { Matricula = val; }

    protected:

    private:
        int Color;
        string Matricula;
};

#endif // CTRANSPORTE_H
