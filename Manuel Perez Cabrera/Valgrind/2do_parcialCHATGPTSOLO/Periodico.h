#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacion.h"

// Clase derivada que representa un periódico
class Periodico : public Publicacion {
private:
    std::string fecha;       // Fecha de publicación (en formato "DD/MM/AAAA")
    std::string seccion;     // Sección principal del periódico

public:
    // Constructor por defecto
    Periodico();

    // Constructor parametrizado
    Periodico(const std::string& titulo, const std::string& autor, int anioPublicacion, const std::string& fecha, const std::string& seccion);

    // Destructor
    ~Periodico();

    // Métodos de acceso (getters y setters)
    std::string getFecha() const;
    void setFecha(const std::string& fecha);

    std::string getSeccion() const;
    void setSeccion(const std::string& seccion);

    // Sobrescritura del método para mostrar información del periódico
    void mostrarInformacion() const override;

    // Sobrescritura de métodos de persistencia
    void guardarEnArchivo(std::ostream& os) const override;
    void cargarDesdeArchivo(std::istream& is) override;
};

#endif // PERIODICO_H
