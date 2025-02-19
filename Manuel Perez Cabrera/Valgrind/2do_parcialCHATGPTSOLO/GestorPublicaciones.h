#ifndef GESTOR_BIBLIOTECA_H
#define GESTOR_BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Publicacion.h"
#include "Libro.h"
#include "Revista.h"

// Clase para gestionar publicaciones de diferentes tipos
class GestorBiblioteca {
private:
    std::vector<Publicacion*> publicaciones; // Vector de punteros a publicaciones

public:
    // Constructor por defecto
    GestorBiblioteca();

    // Destructor para liberar memoria
    ~GestorBiblioteca();

    // Agregar una publicación al gestor
    void agregarPublicacion(Publicacion* publicacion);

    // Buscar una publicación por título
    Publicacion* buscarPorTitulo(const std::string& titulo) const;

    // Eliminar una publicación por título
    void eliminarPorTitulo(const std::string& titulo);

    // Mostrar todas las publicaciones
    void mostrarPublicaciones() const;

    // Persistir las publicaciones en un archivo (texto)
    void guardarEnArchivo(const std::string& nombreArchivo) const;

    // Cargar publicaciones desde un archivo (texto)
    void cargarDesdeArchivo(const std::string& nombreArchivo);
};

#endif // GESTOR_BIBLIOTECA_H
