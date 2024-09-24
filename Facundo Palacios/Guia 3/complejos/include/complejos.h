#ifndef COMPLEJOS_H
#define COMPLEJOS_H

#include <iostream>
using namespace std;

class complejos
{
    public:
        complejos(float real=0.0, float imaginario=0.0);
        complejos(const complejos& other);
        virtual ~complejos();

        float Getreal() const { return real; }
        void Setreal(float val) { real = val; }
        float Getimaginario() const { return imaginario; }
        void Setimaginario(float val) { imaginario = val; }

        //Sobrecarga de operadores
        complejos operator+(const complejos& other);
        complejos operator-(const complejos& other);
        complejos operator*(const complejos& other);
        complejos operator/(const complejos& other);
        complejos& operator=(const complejos& other);

        //Sobrecarga cout y cin
        friend ostream& operator<<(ostream& os,const complejos& other);
        friend istream& operator>>(istream& is,complejos& other);

        //Modulo y fase
        float modulo();
        float fase();


    protected:

    private:
        float real;
        float imaginario;
};

#endif // COMPLEJOS_H
