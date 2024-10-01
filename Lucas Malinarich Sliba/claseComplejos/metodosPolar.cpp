#include "claseComplejos.h"

istream& operator>>(istream &Cin, Polar &valor){
    float num;
    cout<<"|z|: ";
    cin>>num;
    valor.setModulo(num);
    cout<<"\nAlfa: ";
    cin>>num;
    valor.setFase(num);
    return Cin;
}

ostream& operator<<(ostream &Cout, Polar &valor){
    cout<<"|z|="<<valor.getModulo()<<", alfa="<<valor.getFase()<<endl;
    return Cout;
}

Complejos RecTan(float mod, float fas){
    float real, img;
    real=mod*cos(fas);
    img=mod*sin(fas);
    Complejos resultado(real, img);
    return resultado;
}

Polar::Polar(float mod, float fas) : Complejos(mod*cos(fas), mod*sin(fas)){
    setModulo(mod);
    setFase(fas);
}

Polar::~Polar(){ }

void Polar::setModulo(float mod){
    modulo=abs(mod);
}
void Polar::setFase(float fas){
    fase=fas;
    if(abs(fase)>2*PI){
        while(abs(fase)>2*PI)
            fase/=(2*PI);
    }

}

float Polar::getModulo()const{ return modulo; }
float Polar::getFase()const{ return fase; }

Polar& Polar::operator=(const Polar &valor){
    if(this!=&valor){
        setFase(valor.getFase());
        setModulo(valor.getModulo());
    }
    return *this;
}

Polar& Polar::operator=(const Complejos &valor){
    if(this!=&valor){
        float mod=valor.calcularModulo(), fas=valor.calcularAngulo();
        setModulo(mod);
        setFase(fas);
    }
    return *this;
}

float Polar::Modulo(const Complejos &valor)const{
    return valor.calcularModulo();
}

float Polar::Fase(const Complejos &valor)const{
    return valor.calcularAngulo();
}
