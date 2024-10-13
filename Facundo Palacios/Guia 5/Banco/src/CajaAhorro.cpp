#include "CajaAhorro.h"

CajaAhorro::CajaAhorro(string nombre, float saldo, int extracciones):
    CuentaBancaria(nombre, saldo)
{
    Setextracciones(extracciones);
    Setrealizadas(0);
    mes=0;
}

CajaAhorro::~CajaAhorro()
{
    //dtor
}

void CajaAhorro::extraer()
{
    int mes_ult=mes;
    int mes_act=0;
    cout<<"Ingrese el mes actual: ";
    cin>>mes_act;
    cout<<endl;
    if(mes_act!=mes_ult)
    {
        Setrealizadas(0);
        Setmes(mes_act);
    }
    if(Getsaldo()>0 && Getrealizadas()<Getextracciones())
    {
        float actual=Getsaldo();

        float retirar=0.0;
        cout<<"Su saldo disponible es: $"<<actual<<endl;
        cout<<"Ingrese cantidad a retirar: $";
        cin>>retirar;
        cout<<endl;
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
    else if(Getsaldo()<=0 && Getrealizadas()<Getextracciones())
    {
        cout<<"No hay saldo disponible"<<endl;
    }
    else if(Getsaldo()>0 && Getrealizadas()==Getextracciones())
    {
        cout<<"No quedan extracciones disponibles este mes"<<endl;
    }
    else
    {
        cout<<"Estas re seco hermano"<<endl;
    }
}
