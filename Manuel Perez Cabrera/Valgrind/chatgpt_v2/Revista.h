#ifndef REVISTA_H
#define REVISTA_H

#include "Publicacion.h"

class Revista : public Publicacion {
private:
    int numero_edicion_;

public:
    Revista(const std::string& titulo, const std::string& autor, int anio_publicacion, int numero_edicion);
    void mostrar_detalle() const override;
    std::string serializar() const override;

    // Getter y setter
    int obtener_numero_edicion() const;
    void establecer_numero_edicion(int numero_edicion);
};

#endif // REVISTA_H
