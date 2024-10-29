#include <iostream>
#include <cstdlib>                      // funciones abort() y exit()
#include <exception>

using namespace std;

void my_Thandler()
{
    cout << "Dentro de mi funcion terminate\n\n";
    //abort();                          // cuelga la salida
    exit(10);                           // mando un mensaje de salida
}

int main()
{
    //set_terminate(my_Thandler);         // establece el nuevo terminate handler

    try
    {
        cout << "Dentro del bloque try\n\n";
        throw 100;                      // lanzo un error de tipo entero
    }
    catch (double i)                    // captura un error de tipo double
    {
        // manejo del error double ...
    }
    // no hay un catch para entero, por lo que llama a unexpected que por default llama a terminate

    return 0;
}
