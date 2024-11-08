#include <iostream>
#include <limits>


using namespace std;

double leerDouble();

int main()
{
    leerDouble(); //Llamada a la función.
    return 0;
}

///Salida en consola en caso de no ingresar un DOUBLE: basic_ios::clear: iostream error: dato no válido

double leerDouble() //Se declara una función llamada leerDouble que no recibe argumentos y devuelve un valor de tipo double.
{
    cin.exceptions(ios::failbit | ios::badbit); //Se configuran las excepciones de cin (el flujo de entrada estándar) para que lance excepciones
                                                //cuando ocurra un fallo en la entrada (como un tipo de dato incorrecto). ios::failbit indica un fallo de formato
                                                // y ios::badbit indica un fallo en el flujo.
    double dato = 0.0;
    try         //Comienza un bloque que intentará ejecutar el código dentro de él y estará preparado para manejar excepciones.
    {
        cin >> dato;    //Se intenta leer un valor de tipo double desde cin y se almacena en la variable dato.
                        //Si el usuario introduce un valor que no puede ser convertido a double, se lanzará una excepción.
    }
    catch(ios_base::failure & e)    //Se captura cualquier excepción de tipo ios_base::failure que pueda ocurrir en el bloque try. e es una referencia a la excepción lanzada.
    {
        cout << e.what() << ": dato no válido" << endl; //Se imprime un mensaje de error que incluye la descripción de la excepción (obtenida con e.what())
                                                        //seguida del mensaje ": dato no válido". Esto informa al usuario que el dato introducido no es válido.
        cin.clear();    //Se llama a cin.clear() para restablecer el estado del flujo cin, lo que permite realizar nuevas operaciones de entrada tras un fallo.
        cin.ignore(numeric_limits<int>::max(), '\n'); //cin.ignore() se usa para descartar caracteres restantes en el buffer de entrada hasta el siguiente salto de línea ('\n').
                                                      //numeric_limits<int>::max() se utiliza como límite para asegurarse de que se ignoren todos los caracteres restantes, evitando un bucle infinito en caso de entrada no válida.
    }
    return dato;
}
