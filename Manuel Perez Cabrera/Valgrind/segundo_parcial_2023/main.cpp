#include <iostream>
#include "cManejadorServicios.h"

using namespace std;

int main()
{
    cManejadorServicios manejador;

    manejador.cargarServicios("servicios");
    manejador.ImprimirServicios();

     ///cout << manejador.servicios[3]->Getcliente().Getnombre_cliente() ;

    return 0;
}
