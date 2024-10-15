#ifndef CLASEBANCO_H_INCLUDED
#define CLASEBANCO_H_INCLUDED

#include "claseCuenta.h"
#include <vector>

class Banco{
private:
    vector <Cuenta*>cuentas;
public:
    Banco();
    ~Banco();
    void crearCuenta();
    Cuenta* eliminarCuenta();
    //Cuenta* getCuenta(string titular);
    double calcularActivo();
};

#endif // CLASEBANCO_H_INCLUDED
