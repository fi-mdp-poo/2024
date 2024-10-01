#ifndef CLASECOMPLEJOS_H_INCLUDED
#define CLASECOMPLEJOS_H_INCLUDED

#include <cmath>
#include <iostream>
#define PI 3.141592

using namespace std;

class Complejos{
private:
    float compReal, compImaginario;
public:
    friend istream& operator>>(istream&, Complejos&);
    friend ostream& operator<<(ostream&, Complejos&);
    Complejos(float real=0.0, float img=0.0);
    virtual ~Complejos();
    void setDatos(float real, float img);
    float getCompReal()const;
    float getCompImaginario()const;
    float calcularModulo()const;
    float calcularAngulo()const;
    Complejos operator+(const Complejos&);
    Complejos operator-(const Complejos&);
    Complejos operator*(const Complejos&);
    Complejos operator/(const Complejos&);
    Complejos& operator=(const Complejos&);
    Complejos& operator+=(const Complejos&);
    Complejos& operator-=(const Complejos&);
    Complejos& operator*=(const Complejos&);
    Complejos& operator/=(const Complejos&);
    bool operator==(const Complejos&);
    bool operator>(const Complejos&);//Compara m�dulos
    bool operator>=(const Complejos&);
    bool operator<(const Complejos&);//Compara m�dulos
    bool operator<=(const Complejos&);
    bool operator!();
};

class Polar : public Complejos{
public:
    friend istream& operator>>(istream&, Polar&);
    friend ostream& operator<<(ostream&, Polar&);
    friend Complejos RecTan(float mod, float fas);
    //Pasa los datos de la notaci�n polar a la binaria
    Polar(float modulo=0, float fase=0);
    virtual ~Polar();
    void setModulo(float);
    void setFase(float);
    float getModulo()const;
    float getFase()const;
    float Modulo(const Complejos&)const;
    //Obtiene el m�dulo del complejo pasado
    float Fase(const Complejos&)const;
    //Obtiene la fase del complejo pasado
    Polar& operator=(const Polar&);
    Polar& operator=(const Complejos&);
    //La sobrecarga de los operadores * y / ser�an m�s eficientes si se usa la notacin polar
    //Los operadores aritmticos no actualizan los valores de la notaci�n polar
private:
    float modulo, fase;
};

#endif // CLASECOMPLEJOS_H_INCLUDED
