#include "Completo.h"

Completo::Completo(string nombre, string categoria, float montofijo):
    CalculadorImpositivo(nombre, categoria, montofijo)
{
    //ctor
}

Completo::~Completo()
{
    //dtor
}

RecibodePago Completo::calcularimpuesto(int a, int b)
{
    float mv=montovariable(a, b);
    RecibodePago recibo(Getnombre(), mv, Getmontofijo(), Getfactura(Getfacturas(), a), Getfactura(Getfacturas(), b));
    return recibo;
}

float Completo::montovariable(int a, int b)
{
    float montov=0.0;
    float monto_aux=0.0;
    vector <Factura*> fac=Getfacturas();
    for (int i=a-1; i<b; i++)
    {
        Factura* aux=Getfactura(fac, i);
        monto_aux=aux->Getmonto();
        if(monto_aux>5000)
        {
            montov+=monto_aux*0.5;
        }
    }
    return montov;
}
