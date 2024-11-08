#include "Archivo.h"

#include "ArchivoExceptions/ArchivoAperturaException.h"
#include "ArchivoExceptions/ArchivoLecturaException.h"

Archivo::Archivo(const string& nombreArchivo) {
    _abrirArchivo(nombreArchivo);
}

Archivo::~Archivo() {
    if (_archivo.is_open()) {
        _archivo.close();
    }
}

void Archivo::_abrirArchivo(const string& nombreArchivo) {
    _archivo.open(nombreArchivo);
    if (!_archivo.is_open()) {
        throw ArchivoAperturaException(nombreArchivo);
    }
}

void Archivo::imprimirLetrasYPuntos() {
    char caracter;
    while (_archivo.get(caracter)) {
        // Verificar si el carácter es imprimible y es una letra o un signo de puntuación
        if (isprint(caracter) && (isalpha(caracter) || ispunct(caracter))) {
            cout << caracter;
        }
    }

    if (_archivo.bad()) {
        throw ArchivoLecturaException("Problema al leer el archivo");
    }
}

void Archivo::generarArchivoHexadecimal(const string& nombreArchivo) {
    ofstream archivoHex(nombreArchivo);
    if (!archivoHex.is_open()) {
        throw ArchivoAperturaException(nombreArchivo);
    }

    _archivo.clear(); // Limpia el estado de lectura para permitir la relectura
    _archivo.seekg(0, ios::beg); // Vuelve al inicio del archivo

    unsigned char byte; // Almacena cada byte que se lea del archivo.
    int contador = 0; // Lleva la cuenta de la posición de cada byte leído

    while (_archivo.read(reinterpret_cast<char*>(&byte), sizeof(byte))) { // Lee un byte del archivo y lo almacena en `byte`
        if (contador % 16 == 0) { // Cada 16 bytes, imprime un salto de línea y la dirección en hexadecimal.
            /**
             * Imprime contador en formato hexadecimal con un ancho mínimo de 8 caracteres.
             * Si contador tiene menos de 8 caracteres, se rellenará con el carácter definido por setfill ('0')
             * hex imprime el valor en hexadecimal
             */
            cout << endl << setw(8) << setfill('0') << hex << contador << ": "; // Muestra la dirección en la consola en formato hexadecimal con 8 dígitos
            archivoHex << endl << setw(8) << setfill('0') << hex << contador << ": "; // Guarda la dirección en el archivo de salida con el mismo formato.
        }

        cout << setw(2) << setfill('0') << hex << static_cast<int>(byte) << " "; // Imprime el byte en formato hexadecimal con 2 dígitos en la consola.
        archivoHex << setw(2) << setfill('0') << hex << static_cast<int>(byte) << " "; // Guarda el byte en formato hexadecimal en el archivo de salida.

        contador++; // Incrementa el contador para seguir la posición de los bytes.
    }

    archivoHex.close(); // Cierra el archivo de salida después de finalizar la escritura.
}
