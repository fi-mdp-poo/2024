#ifndef CPANTALLA _H
#define CPANTALLA _H

#include "CMatriz.h"
class CPantalla
{
    public:
        CPantalla (CMatriz&);
        virtual ~CPantalla ();

        unsigned int Getrojo() { return rojo; }
        void Setrojo(unsigned int val) { rojo = val; }
        unsigned int Getverde() { return verde; }
        void Setverde(unsigned int val) { verde = val; }
        unsigned int Getazul() { return azul; }
        void Setazul(unsigned int val) { azul = val; }
        friend ostream& operator<<(ostream& os, const CPantalla& p);  // Sobrecarga de <<
        void ajustarColor(unsigned int = 0);
        void borrarVerde();
        void reforzarRojo(unsigned int);
        CMatriz* getPtr();
        unsigned int getColumnas();
        unsigned int getFilas();

    protected:

    private:
        unsigned int rojo;
        unsigned int verde;
        unsigned int azul;
};

#endif // CPANTALLA _H
