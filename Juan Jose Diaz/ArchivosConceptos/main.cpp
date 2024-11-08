#include <iostream>
#include "Archivo/Archivo.h"
#include "Archivo/ArchivoExceptions/ArchivoException.h"

using namespace std;

string getNombreArchivo(const int argc, char* argv[]) {
    if (argc != 2) {
        throw runtime_error("Cantidad de argumentos no válida");
    }

    string nombreArchivo = argv[1];
    return nombreArchivo;
}

struct DatosArchivo {
    string nombreEntrada;
    string nombreSalida;
};

DatosArchivo getDatosArchivo(const int argc, char* argv[]) {
    if (argc != 3) {
        throw runtime_error("Cantidad de argumentos inválida");
    }

    return {
        argv[1],
        argv[2]
    };
}

int main(const int argc, char* argv[]) {
    try {
        const DatosArchivo datosArchivo = getDatosArchivo(argc, argv);
        Archivo archivo(datosArchivo.nombreEntrada);
        archivo.imprimirLetrasYPuntos();
        archivo.generarArchivoHexadecimal(datosArchivo.nombreSalida);
    } catch (const ArchivoException& e) {
        cerr << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Excepción inesperada: " << e.what() << endl;
    }

    return 0;
}
