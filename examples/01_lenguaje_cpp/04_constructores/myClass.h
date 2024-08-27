#ifndef MYCLASS_H
#define MYCLASS_H

#include <inttypes.h>
#include <string.h>

class myClass
{
    public:
        myClass(uint32_t, char, uint32_t);      // constructor por defecto
        myClass(const myClass&);                // constructor de copia
        ~myClass();
        uint32_t GetiValor1() { return iValor1; }        // son funciones inline
        void SetiValor1(uint32_t val) { iValor1 = val; }
        uint32_t GetiValor2() { return iValor2; }
        void SetiValor2(uint32_t val) { iValor2 = val; }
        char GetcLetra() { return cLetra; }
        void SetcLetra(char val) { cLetra = val; }
        char *GetNombre() { return ptrNombre; }
        void SetNombre(char *val) { strcpy(ptrNombre, val); }
    protected:
    private:
        uint32_t iValor1;
        uint32_t iValor2;
        char cLetra;
        char *ptrNombre;
        uint32_t uLong;
};

#endif // MYCLASS_H
