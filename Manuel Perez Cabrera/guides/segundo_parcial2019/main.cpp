#include "ManejadorFiguras.h"

using namespace std;

int main()
{
    ManejadorFiguras mf;

    mf.CargarFiguras();

    mf.ImprimirFiguras();

   cout << "Area total = " << mf.TotalArea() << endl;

    try
    {
        ofstream of("salida.txt");
        if (!of.is_open())
        {
           throw runtime_error("No se pudo abrir el archivo.");
        }


        mf.Get(1)->SetValores(2.0); //cambio el valor del radio del círculo.
        //mf.ImprimirFiguras(); /// testt manu anda bien :)

        mf.Ordenar();

        mf.ImprimirFiguras(of);

        of << "Area total = " << mf.TotalArea() << endl;

        of.close();
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

        return 0;
    }
