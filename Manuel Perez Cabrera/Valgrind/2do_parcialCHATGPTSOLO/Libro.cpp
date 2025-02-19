#include "Libro.h"
#include <iostream>

// Constructor por defecto
Libro::Libro() : Publicacion(), isbn(""), numPaginas(0) {}

// Constructor parametrizado
Libro::Libro(const std::string& titulo, const std::string& autor, int anioPublicacion, const std::string& isbn, int numPaginas)
    : Publicacion(titulo, autor, anioPublicacion), isbn(isbn), numPaginas(numPaginas) {}

// Destructor
Libro::~Libro() {}

// M�todos de acceso (getters y setters)
std::string Libro::getIsbn() const
{
    return isbn;
}

void Libro::setIsbn(const std::string& isbn)
{
    this->isbn = isbn;
}

int Libro::getNumPaginas() const
{
    return numPaginas;
}

void Libro::setNumPaginas(int numPaginas)
{
    this->numPaginas = numPaginas;
}

// Sobrescritura del m�todo para mostrar informaci�n del libro
void Libro::mostrarInformacion() const
{
    std::cout << "Libro: " << titulo << "\nAutor: " << autor << "\n Anio de Publicacion: " << anioPublicacion
              << "\nISBN: " << isbn << "\nNumero de Paginas: " << numPaginas << std::endl;
}

// Sobrescritura de m�todos de persistencia
void Libro::guardarEnArchivo(std::ostream& os) const
{
    os << "Libro\n" << titulo << "\n" << autor << "\n" << anioPublicacion << "\n" << isbn << "\n" << numPaginas << "\n";
}

void Libro::cargarDesdeArchivo(std::istream& is)
{

    std::getline(is, titulo);
    std::getline(is, autor);
    is >> anioPublicacion;
    is.ignore(); // Para ignorar el salto de l�nea despu�s del a�o
    std::getline(is, isbn);
    is >> numPaginas;
    is.ignore(); // Para ignorar el salto de l�nea despu�s del n�mero de p�ginas

}


