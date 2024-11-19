#ifndef CRECTANGULO_H_INCLUDED
#define CRECTANGULO_H_INCLUDED

#include "CFigura.h"

class CRectangulo : public CFigura
{
    public:
        CRectangulo();
        CRectangulo(float, float);
        ~CRectangulo();
        float fGetBase();
        void vSetBase(float);
        float fGetAltura();
        void vSetAltura(float);
        double dCalcArea();
        void vImprimir(ostream& os=cout);
        void SetValores(float, float);
    protected:
    private:
        float Base;
        float Altura;
};

#endif // CRECTANGULO_H_INCLUDED
