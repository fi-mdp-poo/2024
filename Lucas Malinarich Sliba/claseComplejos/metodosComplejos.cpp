#include "claseComplejos.h"

istream& operator>>(istream &Cin, Complejos &valor){
    float real, img;
    cout<<"Componente real: ";
    cin>>real;
    cout<<"\nComponente imaginario: ";
    cin>>img;
    valor.setDatos(real, img);
    return Cin;
}

ostream& operator<<(ostream &Cout, Complejos &valor){
    if(valor.getCompImaginario()>=0)
        cout<<valor.getCompReal()<<"+"<<valor.getCompImaginario()<<"i\n";
    else
        cout<<valor.getCompReal()<<valor.getCompImaginario()<<"i\n";
    return Cout;
}

Complejos::Complejos(float real, float img){
    setDatos(real, img);
}

Complejos::~Complejos(){  }

void Complejos::setDatos(float real, float img){
    compReal=real;
    compImaginario=img;
}

float Complejos::getCompReal()const{ return compReal; }
float Complejos::getCompImaginario()const{ return compImaginario; }

float Complejos::calcularModulo()const{
    float modulo=sqrt(pow(getCompReal(), 2)+pow(getCompImaginario(), 2));
    return modulo;
}
float Complejos::calcularAngulo()const{
    float fase=atan(getCompImaginario()/getCompReal());
    return fase;
}

Complejos Complejos::operator+(const Complejos &valor){
    Complejos resultado;
    float real, img;
    real=getCompReal()+valor.getCompReal();
    img=getCompImaginario()+valor.getCompImaginario();
    resultado.setDatos(real, img);
    return resultado;
}

Complejos Complejos::operator-(const Complejos &valor){
    Complejos resultado;
    float real, img;
    real=getCompReal()-valor.getCompReal();
    img=getCompImaginario()-valor.getCompImaginario();
    resultado.setDatos(real, img);
    return resultado;
}

Complejos Complejos::operator*(const Complejos &valor){
    Complejos resultado;
    float real, img;
    real=0.0;
    img=0.0;
    resultado.setDatos(real, img);
    return resultado;
}

Complejos Complejos::operator/(const Complejos &valor){
    Complejos resultado;
    float real, img;
    real=0.0;
    img=0.0;
    resultado.setDatos(real, img);
    return resultado;
}

Complejos& Complejos::operator=(const Complejos &valor){
    setDatos(valor.getCompReal(), valor.getCompImaginario());
    return *this;
}

Complejos& Complejos::operator+=(const Complejos &valor){
    *this=*this+valor;
    return *this;
}

Complejos& Complejos::operator-=(const Complejos &valor){
    *this=*this-valor;
    return *this;
}

Complejos& Complejos::operator*=(const Complejos &valor){
    *this=(*this)*valor;
    return *this;
}

Complejos& Complejos::operator/=(const Complejos &valor){
    *this=*this/valor;
    return *this;
}

bool Complejos::operator==(const Complejos &valor){
    bool resultado;
    resultado=(getCompReal()&&valor.getCompReal());
    resultado=(resultado&&getCompImaginario()&&valor.getCompImaginario());
    return resultado;
}

bool Complejos::operator>(const Complejos &valor){
    float modulo1, modulo2;
    modulo1=calcularModulo();
    modulo2=valor.calcularModulo();
    return (modulo1>modulo2);
}

bool Complejos::operator>=(const Complejos &valor){
    bool cumple=(*this==valor)||(*this>valor);
    return cumple;
}

bool Complejos::operator<(const Complejos &valor){
    float modulo1, modulo2;
    modulo1=calcularModulo();
    modulo2=valor.calcularModulo();
    return (modulo1<modulo2);
}

bool Complejos::operator<=(const Complejos &valor){
    bool cumple=(*this==valor)||(*this<valor);
    return cumple;
}

bool Complejos::operator!(){
    return (getCompReal()==0&&getCompImaginario()==0);
}
