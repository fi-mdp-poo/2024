#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion {
private:
    std::string genero_;

public:
   // Libro(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& genero);
   Libro(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& genero);

    void mostrar_detalle() const override;
    std::string serializar() const override;

    // Getter y setter
    const std::string& obtener_genero() const;
    void establecer_genero(const std::string& genero);
};

#endif // LIBRO_H
