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
    void setDatos(float, float);
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
    bool operator>(const Complejos&);
    bool operator>=(const Complejos&);
    bool operator<(const Complejos&);
    bool operator<=(const Complejos&);
    bool operator!();
};

class Polar : public Complejos{
public:
    friend Complejos RecTan(float, float);
    Polar(float num1=0, float num2=0);
    ~Polar();
    void setModulo(float);
    void setFase(float);
    float getModulo()const;
    float getFase()const;
    float Modulo(const Complejos&)const;
    float Fase(const Complejos&)const;
    Polar& operator=(const Polar&);
    Polar& operator=(const Complejos&);
private:
    float modulo, fase;
};

#endif // CLASECOMPLEJOS_H_INCLUDED
