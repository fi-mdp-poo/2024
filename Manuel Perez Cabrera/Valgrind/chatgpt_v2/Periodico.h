#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacion.h"
#include <string>

class Periodico : public Publicacion {
private:
    std::string fecha_publicacion_;

public:
    Periodico(const std::string& titulo, const std::string& autor, int anio_publicacion, const std::string& fecha_publicacion);
    void mostrar_detalle() const override;
    std::string serializar() const override;

    // Getter y setter
    const std::string& obtener_fecha_publicacion() const;
    void establecer_fecha_publicacion(const std::string& fecha_publicacion);
};

#endif // PERIODICO_H
