#ifndef CMATRIZ_H
#define CMATRIZ_H
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


class CMatriz
{
    public:
        CMatriz();
        CMatriz(CMatriz&);
         ~CMatriz();

        void cargar(string);
        CMatriz operator+ (int);
        CMatriz& operator+= (const CMatriz&);
        CMatriz& operator= (const CMatriz&);


        void Set_filas(unsigned int);
        void Set_columnas(unsigned int);
        unsigned int Get_component_matriz(unsigned int , unsigned int)const ;
        unsigned int Get_columnas()const;
        unsigned int Get_filas()const;
        friend ostream& operator << (ostream&, CMatriz&);


    protected:
        unsigned int filas;
        unsigned int columnas;
       unsigned int** matriz;

    private:
};

#endif // CMATRIZ_H
