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

class cCorriente: public Cuenta{
private:
    double tope;
    bool verificarTope();
    void setTope(double limite);
public:
    cCorriente(string nombre="\0", double monto=0.0, double limite=0.0);
    virtual ~cCorriente();
    virtual void extraer(double);
    double getTope() const;
};

#define MAXEXTRAC 100
//MAXEXTRAC define la cantidad de extracciones que las cajas de ahorro pueden hacer mensualmente

class cAhorro: public Cuenta{
private:
    int extracciones;
public:
    cAhorro(string nombre="\0", double monto=0.0);
    virtual ~cAhorro();
    virtual void extraer(double);
    void setExtracciones(int);
    int getExtracciones()const;
};

#define MAXMONTO 100
//MAXMONTO define el monto máximo que las cuentas universitarias pueden extraer por día

class cUniversitaria: public cAhorro{
private:
    double montoExtraido;
public:
    cUniversitaria(string nombre="\0", double monto=0.0);
    virtual ~cUniversitaria();
    virtual void extraer(double);
    void setMontoExtraido(double);
    double getMontoExtraido()const;
};

#endif // CLASECUENTA_H_INCLUDED
