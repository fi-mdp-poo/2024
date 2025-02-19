#ifndef GESTOR_BIBLIOTECA_H
#define GESTOR_BIBLIOTECA_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "Libro.h"

/**
 * Clase gen�rica para gestionar una colecci�n de publicaciones.
 * Permite agregar, buscar, eliminar y persistir publicaciones.
 * @tparam T Tipo de publicaci�n a gestionar (debe derivar de Publicacion).
 */
template<class T>
class GestorBiblioteca
{
private:
    std::vector<T> publicaciones_;  // Vector para almacenar las publicaciones.

public:
    // Agrega una nueva publicaci�n al sistema.
    void agregar_publicacion(const T& publicacion)
    {
        publicaciones_.push_back(publicacion);
    }

    // Muestra todas las publicaciones almacenadas.
    void mostrar_publicaciones() const
    {
        if (publicaciones_.empty())
        {
            std::cout << "No hay publicaciones registradas." << std::endl;
            return;
        }

        std::cout << "Lista de publicaciones:" << std::endl;
        for (const auto& pub : publicaciones_)
        {
            pub.mostrar_detalle();
        }
    }

    // Elimina una publicaci�n por �ndice.
    void eliminar_publicacion(size_t indice)
    {
        if (indice >= publicaciones_.size())
        {
            throw std::out_of_range("�ndice fuera de rango. No se puede eliminar la publicaci�n.");
        }
        publicaciones_.erase(publicaciones_.begin() + indice);
    }

    // Busca una publicaci�n por t�tulo (parcial o completo).
    void buscar_publicacion(const std::string& titulo) const
    {
        bool encontrado = false;
        for (const auto& pub : publicaciones_)
        {
            if (pub.obtener_titulo().find(titulo) != std::string::npos)
            {
                pub.mostrar_detalle();
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            std::cout << "No se encontraron publicaciones con el t�tulo: " << titulo << std::endl;
        }
    }

    // Guarda las publicaciones en un archivo de texto.
    void guardar_en_archivo(const std::string& nombre_archivo) const
    {
        std::ofstream archivo(nombre_archivo);
        if (!archivo)
        {
            throw std::ios_base::failure("No se pudo abrir el archivo para guardar.");
        }
        for (const auto& pub : publicaciones_)
        {
            archivo << pub.serializar() << std::endl;
        }
    }

    // Carga las publicaciones desde un archivo de texto.
    void cargar_desde_archivo(const std::string& nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    if (!archivo) {
        throw std::ios_base::failure("No se pudo abrir el archivo para cargar.");
    }

    publicaciones_.clear();
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string tipo, titulo, autor, anio, extra;
        std::getline(iss, tipo, ',');
        std::getline(iss, titulo, ',');
        std::getline(iss, autor, ',');
        std::getline(iss, anio, ',');
        std::getline(iss, extra, ',');

        if (tipo == "Libro") {
            // El �ltimo campo debe ser un string (g�nero) para los libros.
            publicaciones_.push_back(T(titulo, autor, std::stoi(anio), extra));
        } else if (tipo == "Revista") {
            // Para revistas, el �ltimo campo es un entero (n�mero de edici�n).
            publicaciones_.push_back(T(titulo, autor, std::stoi(anio), std::stoi(extra)));
        } else if (tipo == "Periodico") {
            // Para peri�dicos, el �ltimo campo es una fecha en string.
            publicaciones_.push_back(T(titulo, autor, std::stoi(anio), extra));
        } else {
            throw std::invalid_argument("Tipo de publicaci�n desconocido: " + tipo);
        }
    }
}

};

#endif // GESTOR_BIBLIOTECA_H
