#include "CuentaUniversitaria.h"

CuentaUniversitaria::CuentaUniversitaria(string nombre, float saldo):
    CajaAhorro(nombre, saldo, 0)
{
    //ctor
}

CuentaUniversitaria::~CuentaUniversitaria()
{
    //dtor
}

void CuentaUniversitaria::extraer()
{
    if(Getsaldo()>0)
    {
        float actual=Getsaldo();
        float retirar=0.0;
        cout<<"Su saldo disponible es: $"<<actual<<endl;
        cout<<"Ingrese cantidad a retirar: $";
        cin>>retirar;
        if(retirar<=100)
        {
            actual-=retirar;
            if(actual>=0)
            {
                Setsaldo(actual);
                Setrealizadas(Getrealizadas()+1);
                cout<<"Operacion realizada con exito, saldo actual: $"<<actual<<endl;
            }
            else
            {
                cout<<"No se puede retirar dinero que no posee"<<endl;
            }
        }
        else
        {
            cout<<"No se puede retirar mas de $100"<<endl;
        }

    }
    else
    {
        cout<<"No hay saldo disponible"<<endl;
    }

}


