#ifndef REVISTA_H
#define REVISTA_H

#include "Publicacion.h"

// Clase derivada que representa una revista
class Revista : public Publicacion {
private:
    int numero;              // Número de la revista
    int numArticulos;        // Número de artículos

public:
    // Constructor por defecto
    Revista();

    // Constructor parametrizado
    Revista(const std::string& titulo, const std::string& autor, int anioPublicacion, int numero, int numArticulos);

    // Destructor
    ~Revista();

    // Métodos de acceso (getters y setters)
    int getNumero() const;
    void setNumero(int numero);

    int getNumArticulos() const;
    void setNumArticulos(int numArticulos);

    // Sobrescritura del método para mostrar información de la revista
    void mostrarInformacion() const override;

    // Sobrescritura de métodos de persistencia
    void guardarEnArchivo(std::ostream& os) const override;
    void cargarDesdeArchivo(std::istream& is) override;
};

#endif // REVISTA_H
