#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H

#include <string>
using namespace std;

class CTransporte
{
    public:
        CTransporte();
        CTransporte(string, int);
        virtual ~CTransporte();
        string GetMatricula();
        void SetMatricula();
    protected:

    private:
        string matricula;
};

#endif // CTRANSPORTE_H
