#include "cRadio.h"

cRadio::cRadio(float f, TipoDeBanda t,bool p)
{
    frecuencia = f;
    banda = t;
    prendido = p;
}

cRadio::~cRadio()
{
    //dtor
}

void cRadio::setBanda(TipoDeBanda t)
{
    banda = t;
}

void cRadio::setPrendido(bool p)
{
    prendido = p;
}
