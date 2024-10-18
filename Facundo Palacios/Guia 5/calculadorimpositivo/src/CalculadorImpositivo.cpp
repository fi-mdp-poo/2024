#include "CalculadorImpositivo.h"

CalculadorImpositivo::CalculadorImpositivo(string nombre, string categoria, float montofijo)
{
    Setnombre(nombre);
    Setcategoria(categoria);
    Setmontofijo(montofijo);
}

CalculadorImpositivo::~CalculadorImpositivo()
{
    //dtor
}

