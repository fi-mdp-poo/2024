#include <iostream>

#include "C_ManejadordeServicios.h"

using namespace std;

int main()
{
     try {
        ofstream archivo("servicios.txt");
        ofstream archivo2("servicios2.txt");
        if (!archivo.is_open()) {
            throw runtime_error("Error: No se pudo crear el archivo 'servicios.txt'.");
        }

        C_ManejadordeServicios Manejador;
        Manejador.Cargar_Servicios("servicios.bin");
        Manejador.ImprimirServicios();

        Manejador.OrdenarPorFecha();

        Manejador.ImprimirServicios();


        // Usar la función para escribir en el archivo
        Manejador.ImprimirServicios(archivo);

        Manejador.OrdenarPorNombre();

        Manejador.ImprimirServicios();


        // Usar la función para escribir en el archivo
        Manejador.ImprimirServicios(archivo2);

        // Cerrar el archivo
        archivo.close();
    }
   catch (const exception& e) {
       cout<<"Manu mi puta"<<endl;
       cerr << e.what() << '\n';
       return 1;
   }

    return 0;
}
