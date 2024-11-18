#ifndef CFIGURA_H_INCLUDED
#define CFIGURA_H_INCLUDED

#include <iostream>
#include "CColor.h"

using namespace std;

class CFigura
{
    public:
        CFigura();
        virtual ~CFigura();

        CColor colGetForeColor();
        CColor colGetBackColor();
        ///no existe void vSetForeColor(int);
        void vSetForeColor(CColor);
        void vSetBackColor(CColor);
        virtual double dCalcArea() = 0;
        void SetArea(double);
        double GetArea();
        friend ostream& operator<< (ostream&, CFigura&);
        virtual void vImprimir(ostream& os=cout)=0;
//        virtual void SetValores(float, float);
        virtual void SetValores(float);
    private:
        CColor Color_fondo;
        CColor Color_linea;
        double Area;
};

#endif // CFIGURA_H_INCLUDED
