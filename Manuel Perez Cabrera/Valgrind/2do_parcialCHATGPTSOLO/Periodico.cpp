#include "Periodico.h"
#include <iostream>

// Constructor por defecto
Periodico::Periodico() : Publicacion(), fecha(""), seccion("") {}

// Constructor parametrizado
Periodico::Periodico(const std::string& titulo, const std::string& autor, int anioPublicacion, const std::string& fecha, const std::string& seccion)
    : Publicacion(titulo, autor, anioPublicacion), fecha(fecha), seccion(seccion) {}

// Destructor
Periodico::~Periodico() {}

// M�todos de acceso (getters y setters)
std::string Periodico::getFecha() const {
    return fecha;
}

void Periodico::setFecha(const std::string& fecha) {
    this->fecha = fecha;
}

std::string Periodico::getSeccion() const {
    return seccion;
}

void Periodico::setSeccion(const std::string& seccion) {
    this->seccion = seccion;
}

// Sobrescritura del m�todo para mostrar informaci�n del peri�dico
void Periodico::mostrarInformacion() const {
    std::cout << "Periodico: " << titulo << "\nAutor: " << autor << "\nAnio de Publicacion: " << anioPublicacion
              << "\nFecha: " << fecha << "\nSeccion: " << seccion << std::endl;
}

// Sobrescritura de m�todos de persistencia
void Periodico::guardarEnArchivo(std::ostream& os) const {
    os << "Periodico\n" << titulo << "\n" << autor << "\n" << anioPublicacion << "\n" << fecha << "\n" << seccion << "\n";
}

void Periodico::cargarDesdeArchivo(std::istream& is) {
    std::getline(is, titulo);
    std::getline(is, autor);
    is >> anioPublicacion;
    is.ignore(); // Ignorar el salto de l�nea despu�s del a�o
    std::getline(is, fecha);
    std::getline(is, seccion);
}



