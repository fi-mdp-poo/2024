#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // Para manejo de excepciones
#include <fstream>    // Para manejar archivos

using namespace std;

// Guardar las publicaciones en un archivo de texto
template <typename T>
void guardarEnArchivoTexto(const vector<T>& publicaciones, const string& filename) {
    ofstream archivo(filename);
    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo para escribir");
    }

    for (const auto& pub : publicaciones) {
        archivo << pub.getTitulo() << "," << pub.getAutor() << "," << pub.getAnoPublicacion() << "\n";
    }

    archivo.close();
}

// Cargar las publicaciones desde un archivo de texto
template <typename T>
vector<T> cargarDesdeArchivoTexto(const string& filename) {
    ifstream archivo(filename);
    vector<T> publicaciones;

    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo para leer");
    }

    string titulo, autor;
    int ano;
    while (archivo >> titulo >> autor >> ano) {
        // Crear un objeto de tipo T y agregarlo al vector
        publicaciones.push_back(T(titulo, autor, ano));
    }

    archivo.close();
    return publicaciones;
}

// Guardar las publicaciones en un archivo binario
template <typename T>
void guardarEnArchivoBinario(const vector<T>& publicaciones, const string& filename) {
    ofstream archivo(filename, ios::binary);
    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo para escribir en formato binario");
    }

    for (const auto& pub : publicaciones) {
        archivo.write(reinterpret_cast<const char*>(&pub), sizeof(pub));
    }

    archivo.close();
}

// Cargar las publicaciones desde un archivo binario
template <typename T>
vector<T> cargarDesdeArchivoBinario(const string& filename) {
    ifstream archivo(filename, ios::binary);
    vector<T> publicaciones;

    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo para leer en formato binario");
    }

    T pub("", "", 0);
    while (archivo.read(reinterpret_cast<char*>(&pub), sizeof(pub))) {
        publicaciones.push_back(pub);
    }

    archivo.close();
    return publicaciones;
}

#endif // ARCHIVO_H_INCLUDED
