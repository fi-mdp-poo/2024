#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>

class Publicacion {
protected:
    std::string titulo_;
    std::string autor_;
    int anio_publicacion_;

public:
    Publicacion(const std::string& titulo, const std::string& autor, int anio_publicacion);
    virtual ~Publicacion() = default;

    // Métodos virtuales para polimorfismo
    virtual void mostrar_detalle() const = 0;
    virtual std::string serializar() const = 0;

    // Getters y setters
    const std::string& obtener_titulo() const;
    const std::string& obtener_autor() const;
    int obtener_anio_publicacion() const;

    void establecer_titulo(const std::string& titulo);
    void establecer_autor(const std::string& autor);
    void establecer_anio_publicacion(int anio);
};

#endif // PUBLICACION_H
