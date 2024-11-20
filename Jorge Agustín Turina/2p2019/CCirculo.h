#ifndef CCIRCULO_H_INCLUDED
#define CCIRCULO_H_INCLUDED

#include "CFigura.h"

class CCirculo : public CFigura
{
    public:
        CCirculo();
        ~CCirculo();
        double dCalcArea();
        float fGetRadio();
        void vSetRadio(float);
        void vImprimir(ostream& os=cout);
        void SetValores(float);
    protected:
    private:
        float Radio;
};


#endif // CCIRCULO_H_INCLUDED
