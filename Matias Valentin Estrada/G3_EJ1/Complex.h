#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

using namespace std;

class Complex{
    private:
        float real, img;

    public:
        /// Constructores y Destructores ///
        Complex(float r = 0.0, float i = 0.0); // Constructor por defecto
        Complex(const Complex& other); // Constructor de copia
        virtual ~Complex(); // Destructor

        /// Sobrecarga de operadores ///
        Complex& operator=(const Complex& other);
        Complex operator+(const Complex& other);
        Complex operator-(const Complex& other);
        Complex operator*(const Complex& other);
        Complex operator/(const Complex& other);

        /// Entrada y Salida ///
        friend ostream& operator<<(ostream& os, const Complex& other);
        friend istream& operator>>(istream&, Complex& other);


        /// Getters y Setters ///
        void setreal(float r);
        float getreal()const;
        void setimg(float i);
        float getimg()const;
};

#endif // COMPLEX_H_INCLUDED
