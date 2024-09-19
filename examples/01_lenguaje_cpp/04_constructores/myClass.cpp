#include "myClass.h"
#include <string>

myClass::myClass(uint32_t ival, char ccar, uint32_t ilong) :      // constructor por defecto
    iValor1(ival),
    cLetra(ccar),
    uLong(ilong)
{
    ptrNombre = new char[uLong];
}

myClass::myClass(const myClass& orig)                // constructor de copia
{
    iValor1 = orig.iValor1;
    iValor2 = orig.iValor2;
    cLetra = orig.cLetra;
    uLong = orig.uLong;
    ptrNombre = new char[uLong];
    memcpy(ptrNombre, orig.ptrNombre, uLong);
}


myClass::~myClass()
{
    delete [] ptrNombre;
}

