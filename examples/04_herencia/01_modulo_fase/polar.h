#ifndef POLAR_H
#define POLAR_H

/**********
    Libreria para manejar el algebra vectorial, permite sumar, restar
    multiplicar (producto escalar) y dividir 2 vectores.
    Se puede realizar el producto de un vector por un escalar
**********/


#include "complejos.h"

class polar : public complejo
{
    public:
        polar();
        polar(complejo&);
        polar(float, float, bool modo = false);    // modo = false se le pasa real e imaginaria
                                                   //      = true se le pasa modulo y fase
        float GetModulo();
        void SetModulo(float);
        float GetFase();
        void SetFase(float);

        float CalModulo(complejo&);
        float CalFase(complejo&);

        void ToRect();
        void ToPolar();

        polar operator+ (polar&);
        //polar operator+= (polar&);
        polar friend operator* (double, polar&);
        polar operator*= (double);
        double friend operator* (polar &, polar&);
        friend ostream& operator<< (ostream& co, const polar &pol);

    protected:
    private:
        float fModulo;
        float fFase;
};


#endif // POLAR_H
