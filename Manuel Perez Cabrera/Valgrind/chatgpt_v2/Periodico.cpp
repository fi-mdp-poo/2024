#include "Periodico.h"
#include <iostream>

Periodico::Periodico(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& fecha_publicacion)
    : Publicacion(titulo, autor, anio_publicacion), fecha_publicacion_(fecha_publicacion) {}

void Periodico::mostrar_detalle() const {
    std::cout << "Periódico: " << titulo_ << " | Autor: " << autor_
              << " | Año: " << anio_publicacion_ << " | Fecha: " << fecha_publicacion_ << std::endl;
}

std::string Periodico::serializar() const {
    return "Periodico," + titulo_ + "," + autor_ + "," + std::to_string(anio_publicacion_) + "," + fecha_publicacion_;
}

const std::string& Periodico::obtener_fecha_publicacion() const {
    return fecha_publicacion_;
}

void Periodico::establecer_fecha_publicacion(const std::string& fecha_publicacion) {
    fecha_publicacion_ = fecha_publicacion;
}
