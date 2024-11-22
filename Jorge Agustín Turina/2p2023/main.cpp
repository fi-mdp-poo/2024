#include <iostream>
#include "ManejadorServicios.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    ManejadorServicios administrador = ManejadorServicios();
    administrador.cargar_datos2("servicios.bin");




    return 0;
}
