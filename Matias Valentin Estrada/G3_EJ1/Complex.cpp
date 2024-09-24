#include "Complex.h"

///Constructores y Destructor///

// Constructor por defecto
Complex::Complex(float r, float i){
    setreal(r);
    setimg(i);
}

// Constructor de copia
Complex::Complex(const Complex& other){
    setreal(other.getreal());
    setimg(other.getimg());
}

// Destructor
Complex::~Complex(){

}


/// Sobrecarga de operadores ///

// Operador =
Complex& Complex::operator=(const Complex& other){
    setreal(other.getreal());
    setimg(other.getimg());
    return *this;
}

// Operador +
Complex Complex::operator+(const Complex& other){
    Complex result;
    float sumreal = getreal() + other.getreal();
    float sumimg = getimg() + other.getimg();
    result.setreal(sumreal);
    result.setimg(sumimg);
    return result;
}

// Operador -
Complex Complex::operator-(const Complex& other){
    Complex result;
    float sumreal = getreal() - other.getreal();
    float sumimg = getimg() - other.getimg();
    result.setreal(sumreal);
    result.setimg(sumimg);
    return result;
}

// Operador *
Complex Complex::operator*(const Complex& other){
    Complex result;
    float mulreal = getreal()*other.getreal() - getimg()*other.getimg();
    float mulimg = getreal()*other.getimg() + getimg()*other.getreal();
    result.setreal(mulreal);
    result.setimg(mulimg);
    return result;
}

// Operador /
Complex Complex::operator/(const Complex& other){
    Complex result;
    float denominador = other.getreal()*other.getreal() + other.getimg()*other.getimg();
    // Verificamos que el denominador no sea cero
    if(denominador == 0)
    {
        cout << "Error division por cero en numeros complejos." << endl;
        result.setreal(0);
        result.setimg(0);
        return result; // Retorno un complejo nulo
    }
    float divreal = (getreal()*other.getreal() + getimg()*other.getimg()) / denominador;
    float divimg = (getimg()*other.getreal() - getreal()*other.getimg()) / denominador;
    result.setreal(divreal);
    result.setimg(divimg);
    return result;
}

/// Entrada y Salida ///

ostream& operator<<(ostream& os, const Complex& other){
    if(other.getimg() < 0)
    {
        os << other.getreal() << other.getimg() << "i";
    }
    else
    {
        os << other.getreal() << "+" << other.getimg() << "i";
    }
    return os;
}

istream& operator>>(istream& is, Complex& other){
    float aux;
    cout << "Ingrese la componente real: ";
    is >> aux;
    other.setreal(aux);
    cout << endl;
    cout << "Ingrese la componente imaginaria: ";
    is >> aux;
    other.setimg(aux);
    cout << endl;
    return is;
}

///Getters y Setters///

void Complex::setreal(float r){
    real = r;
}

float Complex::getreal()const{
    return real;
}

void Complex::setimg(float i){
    img = i;
}

float Complex::getimg()const{
    return img;
}
