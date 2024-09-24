#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

class CRacional
{
private:
    int numerador;
    int denominador;

    void simplificar();

public:
    CRacional(int num = 0, int den = 1);

    int get_numerador() const;
    int get_denominador() const;

    CRacional  operator+(const CRacional &otro) const;
    CRacional  operator-(const CRacional &otro) const;
    CRacional  operator*(const CRacional &otro) const;
    CRacional  operator/(const CRacional &otro) const;
    CRacional &operator+=(const CRacional &otro);

    bool operator==(const CRacional &otro) const;
    bool operator<(const CRacional &otro) const;
    bool operator>(const CRacional &otro) const;

    CRacional &operator++();
    CRacional  operator++(int);
    CRacional &operator--();
    CRacional  operator--(int);

    CRacional operator-() const;

    friend CRacional operator+(double x, const CRacional &r);
    friend CRacional operator+(const CRacional &r, double x);

    operator double() const;

    friend std::ostream &operator<<(std::ostream &out, const CRacional &r);
    friend std::istream &operator>>(std::istream &in, CRacional &r);
};

#endif // RACIONAL_H