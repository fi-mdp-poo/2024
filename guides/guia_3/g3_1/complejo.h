#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

class complejo
{
  private:
    double real;
    double imaginario;

  public:
    complejo(double r = 0.0, double i = 0.0);

    double get_real() const;
    double get_imaginario() const;

    void set_real(double r);
    void set_imaginario(double i);

    double modulo() const;
    double fase() const;

    complejo operator+(const complejo &other) const;
    complejo operator-(const complejo &other) const;
    complejo operator*(const complejo &other) const;
    complejo operator/(const complejo &other) const;

    friend std::ostream &operator<<(std::ostream &os, const complejo &c);
};

#endif// COMPLEJO_H