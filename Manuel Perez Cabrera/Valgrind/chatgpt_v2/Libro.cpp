#include "Libro.h"
#include <iostream>

//Libro::Libro(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& genero)
//    : Publicacion(titulo, autor, anio_publicacion), genero_(genero) {}

Libro::Libro(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& genero)
    : Publicacion(titulo, autor, anio_publicacion), genero_(genero) {}


void Libro::mostrar_detalle() const {
    std::cout << "Libro: " << titulo_ << " | Autor: " << autor_
              << " | Año: " << anio_publicacion_ << " | Género: " << genero_ << std::endl;
}

std::string Libro::serializar() const {
    return "Libro," + titulo_ + "," + autor_ + "," + std::to_string(anio_publicacion_) + "," + genero_;
}

const std::string& Libro::obtener_genero() const {
    return genero_;
}

void Libro::establecer_genero(const std::string& genero) {
    genero_ = genero;
}
