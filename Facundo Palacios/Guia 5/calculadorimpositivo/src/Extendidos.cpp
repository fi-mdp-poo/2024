#include "Extendidos.h"

Extendidos::Extendidos(string nombre, string categoria, float montofijo) :
    CalculadorImpositivo(nombre, categoria, montofijo)
{
    //ctor
}

Extendidos::~Extendidos()
{
    //dtor
}

RecibodePago Extendidos::calcularimpuesto(int a, int b)
{
    float mv=montovariable(a, b);
    RecibodePago recibo(Getnombre(), mv, Getmontofijo(), Getfactura(Getfacturas(), a), Getfactura(Getfacturas(), b));
    return recibo;
}

float Extendidos::montovariable(int a, int b)
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
        montov+=10;
    }
    return montov;
}
