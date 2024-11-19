#include "ManejadorFiguras.h"

using namespace std;

int main()
{
    ManejadorFiguras mf;

    mf.CargarFiguras();

    mf.ImprimirFiguras();

    cout << "Area total = " << mf.TotalArea() << endl;

    ofstream of("salida.txt");

    mf.Get(1)->SetValores(2.0); //cambio el valor del radio del círculo.

    mf.Ordenar();

    mf.ImprimirFiguras(of);

    of << "Area total = " << mf.TotalArea() << endl;

    of.close();

    return 0;
}
