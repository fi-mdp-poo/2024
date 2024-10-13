#include "Banco.h"

Banco::Banco()
{
    //ctor
}

Banco::~Banco()
{
    //dtor
}

void Banco::agregarcuenta(CuentaBancaria* cuenta)
{
    cuentas.push_back(cuenta);
}

float Banco::calcularactivo()
{
    float activo=0.0;
    for (const auto& cuenta: cuentas)
    {
        activo+=cuenta->Getsaldo();
    }
    return activo;
}
