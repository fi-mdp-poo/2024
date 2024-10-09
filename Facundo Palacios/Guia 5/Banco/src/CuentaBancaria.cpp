#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(string nombre, float saldo)
{
    Settitular(nombre);
    Setsaldo(saldo);
}

CuentaBancaria::~CuentaBancaria()
{
    //dtor
}

void CuentaBancaria::depositar(float cantidad)
{
    float actual=Getsaldo();
    actual+=cantidad;
    Setsaldo(cantidad);
    cout<<"Nuevo saldo: $"<< actual<<endl;
}
