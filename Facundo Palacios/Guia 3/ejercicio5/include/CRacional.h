#ifndef CRACIONAL_H
#define CRACIONAL_H

#include <iostream>
using namespace std;

class CRacional
{
    public:
        //Constructores y Destructor
        CRacional(int num=0, int den=1);
        CRacional(const CRacional& r);
        CRacional(double v);
        virtual ~CRacional();

        //Getters y Setters
        int getNumerador() const;
        void setNumerador(int a);

        int getDenominador() const;
        void setDenominador(int a);

        //Sobrecarga entrada/salida
        friend istream& operator>>(istream& is, CRacional& r);

        //Sobrecarga operadores
        CRacional operator+(const CRacional& r);
        CRacional& operator=(const CRacional& r);
        CRacional& operator+=(const CRacional& r);
        CRacional operator-();
        CRacional operator-(const CRacional& r);
        CRacional operator*(const CRacional& r);
        CRacional operator/(const CRacional& r);
        CRacional& operator++(); //Pre-incremento
        CRacional operator++(int);//Post-incremento
        CRacional& operator--(); //Pre-decremento
        CRacional operator--(int);//Post-decremento

        bool operator==(const CRacional& r);
        bool operator<(const CRacional& r);
        bool operator>(const CRacional& r);
        bool operator!();

        //Sobrecarga operador + para ser usado con double
        friend CRacional operator+(double lhs, const CRacional& rhs);

        // Función de conversión a double
        operator double() const;

    protected:

    private:
        int numerador;
        int denominador;

        void reducir();
        int gcd(int a, int b);
};

ostream& operator<<(ostream& os, CRacional& r);

#endif // CRACIONAL_H
