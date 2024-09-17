#ifndef CLASERACIONAL_H_INCLUDED
#define CLASERACIONAL_H_INCLUDED

class CRacional{
private:
    int numerador, denominador;
public:
    friend std::istream& operator>>(std::istream&, CRacional&);
    friend std::ostream& operator<<(std::ostream&, const CRacional&);
    friend CRacional operator+(const double, const CRacional&);
    CRacional(int num=0, int den=1);
    ~CRacional();
    void setNumerador(int);
    void setDenominador(int);
    int getNumerador()const;
    int getDenominador()const;
    CRacional operator+(const CRacional&);
    CRacional operator-(const CRacional&);
    CRacional operator-();
    CRacional operator*(const CRacional&);
    CRacional operator/(const CRacional&);
    CRacional& operator=(const CRacional&);
    CRacional& operator+=(const CRacional&);
    CRacional& operator-=(const CRacional&);
    CRacional& operator*=(const CRacional&);
    CRacional& operator/=(const CRacional&);
    bool operator==(const CRacional&);
    bool operator<(const CRacional&);
    bool operator>(const CRacional&);
    bool operator!();
    CRacional& operator++();
    CRacional operator++(int);
    CRacional& operator--();
    CRacional operator--(int);
    operator double();
};

#endif // CLASERACIONAL_H_INCLUDED
