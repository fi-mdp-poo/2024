#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(string nombre, float saldo, float tope):
    CuentaBancaria(nombre, saldo)
{
    Settope(tope);
}

CuentaCorriente::~CuentaCorriente()
{
    //dtor
}
