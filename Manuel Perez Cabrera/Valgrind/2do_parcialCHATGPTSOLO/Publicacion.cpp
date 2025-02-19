#include "Publicacion.h"
#include <iostream>

// Constructor por defecto
Publicacion::Publicacion() : titulo(""), autor(""), anioPublicacion(0) {}

// Constructor parametrizado
Publicacion::Publicacion(const std::string& titulo, const std::string& autor, int anioPublicacion)
    : titulo(titulo), autor(autor), anioPublicacion(anioPublicacion) {}

// Destructor virtual
Publicacion::~Publicacion() {}

// Métodos de acceso (getters y setters)
std::string Publicacion::getTitulo() const {
    return titulo;
}

void Publicacion::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}

std::string Publicacion::getAutor() const {
    return autor;
}

void Publicacion::setAutor(const std::string& autor) {
    this->autor = autor;
}

int Publicacion::getAnioPublicacion() const {
    return anioPublicacion;
}

void Publicacion::setAnioPublicacion(int anioPublicacion) {
    this->anioPublicacion = anioPublicacion;
}
