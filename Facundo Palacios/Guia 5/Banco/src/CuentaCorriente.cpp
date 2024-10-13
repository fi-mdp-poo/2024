#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(string nombre, float saldo, float tope):
    CuentaBancaria(nombre, saldo)
{
    Settope(tope);
    Setuso(tope);
}

CuentaCorriente::~CuentaCorriente()
{
    //dtor
}

void CuentaCorriente::extraer()
{
    float tope=Getuso();
    float saldo=Getsaldo();
    int origen=0;
    float retirar=0.0;
    cout<<"Su saldo disponible es: $"<<saldo<<endl;
    cout<<"Le queda para operar en descubierto: $"<< tope<<endl;
    cout<<"Ingrese cantidad a retirar: $";
    cin>>retirar;
    cout<<"Que dinero quiere utilizar? 0: saldo, 1: descubierto"<<endl;
    cin>>origen;
    if(origen)
    {
        tope-=retirar;
        if(tope>=0)
        {
            Setuso(tope);
            cout<<"Extracción realizada con exito, dinero disponible para operar en descubierto: $"<<tope<<endl;
        }
        else
        {
            cout<<"No se puede realizar la extraccion"<<endl;
        }
    }
    else
    {
        saldo-=retirar;
        if(saldo>=0)
        {
            Setsaldo(saldo);
            cout<<"Extracción realizada con exito, su saldo actual es: $"<<saldo<<endl;
        }
        else
        {
            cout<<"No se puede realizar la extraccion"<<endl;
        }
    }
}
