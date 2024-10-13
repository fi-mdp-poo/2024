#include "CuentaUniversitaria.h"

CuentaUniversitaria::CuentaUniversitaria(string nombre, float saldo):
    CajaAhorro(nombre, saldo, 0)
{
    dia=0;
    Setextraida(0.0);
}

CuentaUniversitaria::~CuentaUniversitaria()
{
    //dtor
}

void CuentaUniversitaria::extraer()
{
    int dia_ult=Getdia();
    int mes_ult=Getmes();
    int dia_act=0;
    int mes_act=0;
    cout<<"Ingrese dia y mes actual: ";
    cin>>dia_act;
    cout<<"/";
    cin>>mes_act;
    if(dia_act!=dia_ult || mes_act!=mes_ult)
    {
        Setdia(dia_act);
        Setmes(mes_act);
        Setextraida(0.0);
    }
    float extraido=Getextraida();
    if (extraido<100)
    {
        if(Getsaldo()>0)
        {
            float actual=Getsaldo();
            float retirar=0.0;
            cout<<"Su saldo disponible es: $"<<actual<<endl;
            cout<<"Ingrese cantidad a retirar: $";
            cin>>retirar;
            if(retirar+extraido<=100)
            {
                actual-=retirar;
                if(actual>=0)
                    Setsaldo(actual);
                Setextraida(retirar+extraido);
                cout<<"Operacion realizada con exito, saldo actual: $"<<actual<<endl;
            }
            else
            {
                cout<<"No se puede retirar mas de $100 diarios"<<endl;
            }
        }
        else
        {
            cout<<"No hay saldo disponible, tas re seco"<<endl;
        }

    }
    else
    {
        cout<<"Ya extrajo el limite permitido por dia"<<endl;
    }

}






