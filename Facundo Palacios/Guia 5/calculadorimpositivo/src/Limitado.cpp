#include "Limitado.h"
#include "Factura.h"

Limitado::Limitado(string nombre, string categoria, float montofijo) :
    CalculadorImpositivo(nombre, categoria, montofijo)
{
    //ctor
}

Limitado::~Limitado()
{
    //dtor
}

RecibodePago Limitado::calcularimpuesto(int a, int b)
{
    float mv=montovariable(a, b);
    RecibodePago recibo(Getnombre(), mv, Getmontofijo(), Getfactura(Getfacturas(), a), Getfactura(Getfacturas(), b));
    return recibo;
}

float Limitado::montovariable(int a, int b)
{
    float montov=0.0;
    float monto_aux=0.0;
    vector <Factura*> fac=Getfacturas();
    for (int i=a-1; i<b; i++)
    {
        Factura* aux=Getfactura(fac, i);
        monto_aux=aux->Getmonto();
        montov+=monto_aux*0.15;
    }
    return montov;
}
