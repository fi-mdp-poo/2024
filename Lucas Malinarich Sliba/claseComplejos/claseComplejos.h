#ifndef CLASECOMPLEJOS_H_INCLUDED
#define CLASECOMPLEJOS_H_INCLUDED

#include <cmath>
#include <iostream>

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
    bool operator>(const Complejos&);//Compara módulos
    bool operator>=(const Complejos&);
    bool operator<(const Complejos&);//Compara módulos
    bool operator<=(const Complejos&);
    bool operator!();
};

class Polar : public Complejos{
public:
    friend istream& operator>>(istream&, Polar&);
    friend ostream& operator<<(ostream&, Polar&);
    friend Complejos RecTan(float mod, float fas);
    //Calcula los componentes del plano complejo
    Polar(float modulo=0, float fase=0);
    virtual ~Polar();
    void setModulo(float);
    void setFase(float);
    float getModulo()const;
    float getFase()const;
    float Modulo(const Complejos&)const;
    //Obtiene el módulo del complejo pasado
    float Fase(const Complejos&)const;
    //Obtiene la fase del complejo pasado
    Polar& operator=(const Polar&);
    Polar& operator=(const Complejos&);
    //El comportamiento heredaro no resulta muy útil ahora mismo
    //Los operadores a sobrecargar ahora tienen que realizar otras instrucciones a las de la clase base
private:
    float modulo, fase;
};

#endif // CLASECOMPLEJOS_H_INCLUDED
