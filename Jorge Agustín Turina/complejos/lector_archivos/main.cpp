#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Utilizar el namespace std

int main() {
    // Nombre del archivo de texto
    string nombreArchivo = "mi_archivo.txt";

    // Abrir el archivo en modo de escritura
    ofstream archivoEscritura(nombreArchivo);

    // Verificar si se pudo abrir el archivo
    if (!archivoEscritura.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return 1; // Salir con un código de error
    }

    // Escribir texto en el archivo
    string texto = "Este es un ejemplo de texto que se escribira en el archivo. un numero 45.4";
    archivoEscritura << texto << endl;

    // Cerrar el archivo de escritura
    archivoEscritura.close();

    // Abrir el archivo en modo de lectura
    ifstream archivoLectura(nombreArchivo);

    /*// Verificar si se pudo abrir el archivo
    if (!archivoLectura.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return 1; // Salir con un código de error
    }

    // Leer y mostrar el contenido del archivo
    string linea;
    while (getline(archivoLectura, linea)) {
        cout << linea << endl;
    }

    // Cerrar el archivo de lectura
    archivoLectura.close();
*/


    char caracter;
    /**while (archivoLectura.get(caracter) && caracter != 'j') {
        cout << caracter;
    }*/
    string test;
    getline(archivoLectura,test, 's'); //lee hasta s, donde lo encuentra corta NO SE INCLUYE EN el string
    archivoLectura.get(caracter);
    cout <<"leo:"<< test<< "leido, despues sigue" << caracter << endl;


    if (!archivoLectura.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return 1; // Salir con un código de error
    }

    return 0; // Salida exitosa
}




