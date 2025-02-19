#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacion.h"

// Clase derivada que representa un peri�dico
class Periodico : public Publicacion {
private:
    std::string fecha;       // Fecha de publicaci�n (en formato "DD/MM/AAAA")
    std::string seccion;     // Secci�n principal del peri�dico

public:
    // Constructor por defecto
    Periodico();

    // Constructor parametrizado
    Periodico(const std::string& titulo, const std::string& autor, int anioPublicacion, const std::string& fecha, const std::string& seccion);

    // Destructor
    ~Periodico();

    // M�todos de acceso (getters y setters)
    std::string getFecha() const;
    void setFecha(const std::string& fecha);

    std::string getSeccion() const;
    void setSeccion(const std::string& seccion);

    // Sobrescritura del m�todo para mostrar informaci�n del peri�dico
    void mostrarInformacion() const override;

    // Sobrescritura de m�todos de persistencia
    void guardarEnArchivo(std::ostream& os) const override;
    void cargarDesdeArchivo(std::istream& is) override;
};

#endif // PERIODICO_H
