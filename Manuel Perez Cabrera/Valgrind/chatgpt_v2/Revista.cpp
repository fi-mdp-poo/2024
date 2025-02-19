#include "Revista.h"
#include <iostream>

Revista::Revista(const std::string& titulo, const std::string& autor, int anio_publicacion, int numero_edicion)
    : Publicacion(titulo, autor, anio_publicacion), numero_edicion_(numero_edicion) {}

void Revista::mostrar_detalle() const {
    std::cout << "Revista: " << titulo_ << " | Autor: " << autor_
              << " | Año: " << anio_publicacion_ << " | Edición: " << numero_edicion_ << std::endl;
}

std::string Revista::serializar() const {
    return "Revista," + titulo_ + "," + autor_ + "," + std::to_string(anio_publicacion_) + "," + std::to_string(numero_edicion_);
}

int Revista::obtener_numero_edicion() const {
    return numero_edicion_;
}

void Revista::establecer_numero_edicion(int numero_edicion) {
    numero_edicion_ = numero_edicion;
}
