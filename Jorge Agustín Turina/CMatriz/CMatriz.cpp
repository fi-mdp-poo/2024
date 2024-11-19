#include "CMatriz.h"

CMatriz::CMatriz(int _filas , int _columnas, unsigned int* _datos)
{
   filas = _filas;
   columnas = _columnas;
   datos = _datos;
}

CMatriz::~CMatriz()
{
    //dtor
}

void CMatriz::cargar(char*)
{


}


ostream& operator<<(ostream& os, const CMatriz& m){


    return os;
}

CMatriz& CMatriz::operator=(const CMatriz& other){
    CMatriz a;
    return a;
}
CMatriz& CMatriz::operator+=(const CMatriz& other){
}
