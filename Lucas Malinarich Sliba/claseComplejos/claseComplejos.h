#ifndef CLASECOMPLEJOS_H_INCLUDED
#define CLASECOMPLEJOS_H_INCLUDED

class Complejos{
private:
    float compReal, compImaginario;
public:
    Complejos();
    Complejos(float, float);
    ~Complejos();
    void setDatos(float, float);
    float getCompReal();
    float getCompImaginario();
    float calcularModulo();
    float calcularAngulo();
    void sumar();
    void restar();
    void multiplicar();
    void dividir();
    Complejos operator+(const Complejos&);
    Complejos operator-(const Complejos&);
    Complejos operator*(const Complejos&);
    Complejos operator/(const Complejos&);
    Complejos operator=(const Complejos&);
    Complejos operator+=(const Complejos&);
    Complejos operator-=(const Complejos&);
    Complejos operator*=(const Complejos&);
    Complejos operator/=(const Complejos&);
};

#endif // CLASECOMPLEJOS_H_INCLUDED
