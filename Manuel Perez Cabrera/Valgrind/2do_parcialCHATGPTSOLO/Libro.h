#ifndef LIBRO_H
#define LIBRO_H
#include <string>
#include "Publicacion.h"

using namespace std;
// Clase derivada que representa un libro
class Libro : public Publicacion
{
private:
    std::string isbn;        // ISBN del libro
    int numPaginas;          // Número de páginas

public:
    // Constructor por defecto
    Libro();

    // Constructor parametrizado
    Libro(const std::string& titulo, const std::string& autor, int anioPublicacion, const std::string& isbn, int numPaginas);

    // Destructor
    ~Libro();

    // Métodos de acceso (getters y setters)
    std::string getIsbn() const;
    void setIsbn(const std::string& isbn);

    int getNumPaginas() const;
    void setNumPaginas(int numPaginas);

    // Sobrescritura del método para mostrar información del libro
    void mostrarInformacion() const override;

    // Sobrescritura de métodos de persistencia
    void guardarEnArchivo(std::ostream& os) const override;
    void cargarDesdeArchivo(std::istream& is) override;
};

#endif // LIBRO_H
