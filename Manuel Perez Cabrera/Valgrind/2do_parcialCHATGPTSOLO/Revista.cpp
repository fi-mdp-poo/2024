#include "Revista.h"
#include <iostream>

// Constructor por defecto
Revista::Revista() : Publicacion(), numero(0), numArticulos(0) {}

// Constructor parametrizado
Revista::Revista(const std::string& titulo, const std::string& autor, int anioPublicacion, int numero, int numArticulos)
    : Publicacion(titulo, autor, anioPublicacion), numero(numero), numArticulos(numArticulos) {}

// Destructor
Revista::~Revista() {}

// M�todos de acceso (getters y setters)
int Revista::getNumero() const {
    return numero;
}

void Revista::setNumero(int numero) {
    this->numero = numero;
}

int Revista::getNumArticulos() const {
    return numArticulos;
}

void Revista::setNumArticulos(int numArticulos) {
    this->numArticulos = numArticulos;
}

// Sobrescritura del m�todo para mostrar informaci�n de la revista
void Revista::mostrarInformacion() const {
    std::cout << "Revista: " << titulo << "\nAutor: " << autor << "\n Anio de Publicacion: " << anioPublicacion
              << "\nNumero: " << numero << "\nNumero de Articulos: " << numArticulos << std::endl;
}

// Sobrescritura de m�todos de persistencia
void Revista::guardarEnArchivo(std::ostream& os) const {
    os << "Revista\n" << titulo << "\n" << autor << "\n" << anioPublicacion << "\n" << numero << "\n" << numArticulos << "\n";
}

void Revista::cargarDesdeArchivo(std::istream& is) {
    std::getline(is, titulo);
    std::getline(is, autor);
    is >> anioPublicacion;
    is.ignore(); // Para ignorar el salto de l�nea despu�s del a�o
    is >> numero;
    is.ignore(); // Para ignorar el salto de l�nea despu�s del n�mero
    is >> numArticulos;
    is.ignore(); // Para ignorar el salto de l�nea despu�s del n�mero de art�culos
}


