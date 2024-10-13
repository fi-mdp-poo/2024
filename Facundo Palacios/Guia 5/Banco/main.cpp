#include <iostream>
#include <string>
#include "Banco.h"
#include "CuentaCorriente.h"
#include "CajaAhorro.h"
#include "CuentaUniversitaria.h"

using namespace std;

int main()
{
    Banco Boca;
    CuentaBancaria* roman= new CuentaCorriente("Roman Riquelme", 70000, 5000);
    CuentaBancaria* gago= new CuentaUniversitaria("Fernando Gago", 3000);
    CuentaBancaria* milton= new CajaAhorro("Milton Gimenez", 40000, 1);

    Boca.agregarcuenta(roman);
    Boca.agregarcuenta(gago);
    Boca.agregarcuenta(milton);
    cout<<"Activo inicial: $ "<< Boca.calcularactivo() <<endl;

    roman->extraer();
    milton->extraer();
    milton->extraer();
    gago->extraer();
    gago->extraer();

    cout<<"Activo actual: $"<<Boca.calcularactivo()<<endl;
    return 0;
}
