#include "GestorBiblioteca.h"
#include "Libro.h"
#include "Revista.h"
#include "Periodico.h"

int main() {
    try {
        // Crear el gestor de biblioteca para libros.
        GestorBiblioteca<Libro> gestor_libros;

        // Agregar libros al sistema.
        gestor_libros.agregar_publicacion(Libro("C++ Primer", "Lippman", 2013, "Educación"));
        gestor_libros.agregar_publicacion(Libro("Clean Code", "Robert C. Martin", 2008, "Programación"));

        std::cout << "Publicaciones añadidas: " << std::endl;
        gestor_libros.mostrar_publicaciones();

        // Buscar un libro.
        std::cout << "\nBuscando libros con 'C++':" << std::endl;
        gestor_libros.buscar_publicacion("C++");

        // Eliminar una publicación.
        std::cout << "\nEliminando el primer libro..." << std::endl;
        gestor_libros.eliminar_publicacion(0);

        std::cout << "Publicaciones restantes: " << std::endl;
        gestor_libros.mostrar_publicaciones();

        // Guardar publicaciones en un archivo.
        std::cout << "\nGuardando publicaciones en archivo 'libros.txt'..." << std::endl;
        gestor_libros.guardar_en_archivo("libros.txt");

        // Cargar publicaciones desde archivo.
        std::cout << "\nCargando publicaciones desde archivo 'libros.txt'..." << std::endl;
        gestor_libros.cargar_desde_archivo("libros.txt");
        gestor_libros.mostrar_publicaciones();

    } catch (const std::exception& ex) {
        // Manejo de excepciones generales.
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
