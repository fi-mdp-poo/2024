#ifndef CPANTALLA_H
#define CPANTALLA_H
#include "CMatriz.h"

using namespace std;

class CPantalla
{
    public:
        CPantalla(CMatriz&);
        virtual ~CPantalla();

        friend ostream& operator << (ostream&, CPantalla&);
        unsigned int** getPtr();
        void ajustarColor(int);
        void borrarVerde();
        void reforzarRojo(float);
        void Set_filas(unsigned int);
        void Set_columnas(unsigned int);
        unsigned int Get_component_matriz(unsigned int , unsigned int)const ;
        unsigned int Get_columnas()const;
        unsigned int Get_filas()const;

    protected:
        unsigned int** matriz;
        unsigned int filas;
        unsigned int columnas;

    private:
};

#endif // CPANTALLA_H
