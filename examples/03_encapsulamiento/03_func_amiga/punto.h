#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <math.h>

using namespace std;

class punto
{
    public:
        punto(float, float);
        ~punto();
        float Get_x();
        float Get_y();
        void Set_x(float);
        void Set_y(float);
        void Visualizar();
        float CalcularDistancia(punto);
        friend float CalcularDistancia(punto, punto);
    protected:
    private:
        float x, y;
};

#endif // PUNTO_H
