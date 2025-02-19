#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>

// Clase base que representa una publicación genérica
class Publicacion
{
protected:
    std::string titulo;      // Título de la publicación
    std::string autor;       // Autor de la publicación
    int anioPublicacion;     // Año de publicación

public:
    // Constructor por defecto
    Publicacion();

    // Constructor parametrizado
    Publicacion(const std::string& titulo, const std::string& autor, int anioPublicacion);

    // Destructor virtual para asegurar la correcta eliminación de objetos derivados
    virtual ~Publicacion();

    // Métodos de acceso (getters y setters)
    std::string getTitulo() const;
    void setTitulo(const std::string& titulo);

    std::string getAutor() const;
    void setAutor(const std::string& autor);

    int getAnioPublicacion() const;
    void setAnioPublicacion(int anioPublicacion);

    // Método virtual puro para mostrar información de la publicación
    virtual void mostrarInformacion() const = 0;

    // Métodos para persistencia (serialización y deserialización)
    virtual void guardarEnArchivo(std::ostream& os) const = 0;
    virtual void cargarDesdeArchivo(std::istream& is) = 0;
};

#endif // PUBLICACION_H

