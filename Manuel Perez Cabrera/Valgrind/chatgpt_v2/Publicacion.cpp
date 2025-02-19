#include "Publicacion.h"
#include <iostream>

Publicacion::Publicacion(const std::string& titulo, const std::string& autor, int anio_publicacion)
    : titulo_(titulo), autor_(autor), anio_publicacion_(anio_publicacion) {}

const std::string& Publicacion::obtener_titulo() const {
    return titulo_;
}

const std::string& Publicacion::obtener_autor() const {
    return autor_;
}

int Publicacion::obtener_anio_publicacion() const {
    return anio_publicacion_;
}

void Publicacion::establecer_titulo(const std::string& titulo) {
    titulo_ = titulo;
}

void Publicacion::establecer_autor(const std::string& autor) {
    autor_ = autor;
}

void Publicacion::establecer_anio_publicacion(int anio) {
    anio_publicacion_ = anio;
}
