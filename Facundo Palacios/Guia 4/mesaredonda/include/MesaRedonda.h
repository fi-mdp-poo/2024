#ifndef MESAREDONDA_H
#define MESAREDONDA_H

#include "mesa.h"
#include "circulo.h"
#include <iostream>

using namespace std;


class MesaRedonda: public circulo, mesa
{
    public:
        MesaRedonda();
        MesaRedonda(int color, float altura, float radio);
        virtual ~MesaRedonda();

        int Getcolor() { return color; }
        void Setcolor(int val) { color = val; }

        friend ostream& operator<<(ostream& os, MesaRedonda& me);

    protected:

    private:
        int color;
};

#endif // MESAREDONDA_H
