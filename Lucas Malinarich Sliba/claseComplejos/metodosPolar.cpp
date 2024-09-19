#include "claseComplejos.h"

Complejos RecTan(float num1, float num2){
    Complejos resultado;
    return resultado;
}

Polar::Polar(float num1, float num2){
    setFase(num1);
    setModulo(num2);
}

Polar::~Polar(){ }

void Polar::setModulo(float mod){
    modulo=mod;
}
void Polar::setFase(float fas){
    fase=fas;
}

float Polar::getModulo()const{ return modulo; }
float Polar::getFase()const{ return fase; }

//float Polar::Modulo(const Complejos&)const;
//float Fase(const Complejos&)const;
//Polar& operator=(const Polar&);
//Polar& operator=(const Complejos&);
