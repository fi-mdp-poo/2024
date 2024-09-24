#include "complejo.h"
#include <cmath>

complejo::complejo(double r, double i) : real(r), imaginario(i) {}

double complejo::get_real() const { return real; }

double complejo::get_imaginario() const { return imaginario; }

void complejo::set_real(double r) { real = r; }

void complejo::set_imaginario(double i) { imaginario = i; }

double complejo::modulo() const { return sqrt(real * real + imaginario * imaginario); }

double complejo::fase() const
{
    double angulo = atan2(imaginario, real);
    if (angulo < 0) { angulo += 2 * M_PI; }
    return angulo;
}

complejo complejo::operator+(const complejo &other) const
{
    return complejo(real + other.real, imaginario + other.imaginario);
}

complejo complejo::operator-(const complejo &other) const
{
    return complejo(real - other.real, imaginario - other.imaginario);
}

complejo complejo::operator*(const complejo &other) const
{
    double r = real * other.real - imaginario * other.imaginario;
    double i = real * other.imaginario + imaginario * other.real;
    return complejo(r, i);
}

complejo complejo::operator/(const complejo &other) const
{
    double divisor = other.real * other.real + other.imaginario * other.imaginario;
    double r = (real * other.real + imaginario * other.imaginario) / divisor;
    double i = (imaginario * other.real - real * other.imaginario) / divisor;
    return complejo(r, i);
}

std::ostream &operator<<(std::ostream &os, const complejo &c)
{
    os << c.real << " + " << c.imaginario << "i";
    return os;
}