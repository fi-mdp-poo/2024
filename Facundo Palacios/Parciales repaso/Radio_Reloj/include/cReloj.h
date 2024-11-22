#ifndef CRELOJ_H
#define CRELOJ_H

#include <string>
#include <iostream>
#include "cTime.h"

using namespace std;

class cReloj
{
    public:
        cReloj(int h=0, int m=0, int s=0, string marc="default");
        virtual ~cReloj();

        cTime Gethora() { return hora; }
        void Sethora(int h, int m, int s);
        string Getmarca() { return marca; }
        void Setmarca(string val) { marca = val; }

    protected:

    private:
        cTime hora;
        string marca;
};

#endif // CRELOJ_H
