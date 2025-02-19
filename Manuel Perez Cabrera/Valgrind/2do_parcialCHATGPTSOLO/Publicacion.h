#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>

// Clase base que representa una publicaci�n gen�rica
class Publicacion
{
protected:
    std::string titulo;      // T�tulo de la publicaci�n
    std::string autor;       // Autor de la publicaci�n
    int anioPublicacion;     // A�o de publicaci�n

public:
    // Constructor por defecto
    Publicacion();

    // Constructor parametrizado
    Publicacion(const std::string& titulo, const std::string& autor, int anioPublicacion);

    // Destructor virtual para asegurar la correcta eliminaci�n de objetos derivados
    virtual ~Publicacion();

    // M�todos de acceso (getters y setters)
    std::string getTitulo() const;
    void setTitulo(const std::string& titulo);

    std::string getAutor() const;
    void setAutor(const std::string& autor);

    int getAnioPublicacion() const;
    void setAnioPublicacion(int anioPublicacion);

    // M�todo virtual puro para mostrar informaci�n de la publicaci�n
    virtual void mostrarInformacion() const = 0;

    // M�todos para persistencia (serializaci�n y deserializaci�n)
    virtual void guardarEnArchivo(std::ostream& os) const = 0;
    virtual void cargarDesdeArchivo(std::istream& is) = 0;
};

#endif // PUBLICACION_H

