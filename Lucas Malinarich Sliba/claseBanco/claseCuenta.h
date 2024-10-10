#ifndef CLASECUENTA_H_INCLUDED
#define CLASECUENTA_H_INCLUDED

#include <iostream>

using namespace std;

class Cuenta{
protected:
    string titular;
    double saldo;
public:
    friend ostream& operator<<(ostream&, const Cuenta&);
    Cuenta(string nombre="\0", double monto=0.0);
    virtual ~Cuenta();
    void setTitular(string nombre);
    void setSaldo(double monto);
    string getTitular()const;
    double getSaldo()const;

    void depositar(double monto);
    virtual void extraer(double monto);
};

//class cCorriente: public Cuenta{
//
//};
//
//class cAhorro: public Cuenta{
//
//};
//
//class cUniversitaria: public cAhorro{
//
//};

#endif // CLASECUENTA_H_INCLUDED
