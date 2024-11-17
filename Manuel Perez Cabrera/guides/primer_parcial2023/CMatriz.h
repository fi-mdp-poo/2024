#ifndef CMATRIZ_H
#define CMATRIZ_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class CMatriz
{
    public:
        CMatriz();
        virtual ~CMatriz();

        void cargar(string);
        friend ostream& operator << (ostream&, CMatriz&);
        void Set_filas(unsigned int);
        void Set_columnas(unsigned int);
        unsigned int Get_columnas();
        unsigned int Get_filas();

    protected:
        unsigned int filas;
        unsigned int columnas;
       unsigned int** matriz;

    private:
};

#endif // CMATRIZ_H
