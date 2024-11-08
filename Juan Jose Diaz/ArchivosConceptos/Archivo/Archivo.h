#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <cctype> // header necesario para utilizar las funciones isprint() y isalpha()

using namespace std;

class Archivo {
    private:
        ifstream _archivo;

        void _abrirArchivo(const string& nombreArchivo);

    public:
        explicit Archivo(const string& nombreArchivo);

        ~Archivo();

        void imprimirLetrasYPuntos();

        void generarArchivoHexadecimal(const string& nombreArchivo);
};

#endif //ARCHIVO_H
