#include <iostream>
#include <memory>
#include "GestorPublicaciones.h"
#include "Libro.h"
#include "Revista.h"
#include "Periodico.h"

int main() {
    try {
        // Crear el gestor de biblioteca
        GestorBiblioteca gestor;

        // Agregar publicaciones
        Publicacion* libro1 =new Libro("El Señor de los Anillos", "J.R.R. Tolkien", 1954, "Fantasía", 1200);
        Publicacion* revista1 =new Revista("National Geographic", "Varios", 2023, 1, 150);
        Publicacion* periodico1 =new Periodico("El País", "Editorial Prensa Ibérica", 2024, "27/11/2024", "Internacional");

        gestor.agregarPublicacion(libro1);
        gestor.agregarPublicacion(revista1);
        gestor.agregarPublicacion(periodico1);

        // Mostrar todas las publicaciones
        std::cout << "Publicaciones actuales en la biblioteca:\n";
        gestor.mostrarPublicaciones();

        // Buscar una publicación
        std::cout << "\nBuscando 'El Senior de los Anillos':\n";
        try {
            auto encontrado = gestor.buscarPorTitulo("El Senior de los Anillos");
            encontrado->mostrarInformacion();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Intentar buscar una publicación inexistente
        std::cout << "\nBuscando 'Revista Inexistente':\n";
        try {
            auto encontrado = gestor.buscarPorTitulo("Revista Inexistente");
            encontrado->mostrarInformacion();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Eliminar una publicación
        std::cout << "\nEliminando 'National Geographic':\n";
        try {
            gestor.eliminarPorTitulo("National Geographic");
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Mostrar todas las publicaciones tras la eliminación
        std::cout << "\nPublicaciones tras eliminar 'National Geographic':\n";
        gestor.mostrarPublicaciones();

        // Guardar publicaciones en un archivo
        std::cout << "\nGuardando publicaciones en 'publicaciones.txt'...\n";
        gestor.guardarEnArchivo("publicaciones.txt");

        // Limpiar las publicaciones del gestor y cargar desde el archivo
        std::cout << "\nCargando publicaciones desde 'publicaciones.txt'...\n";
        gestor = GestorBiblioteca(); // Crear un nuevo gestor vacío
        gestor.cargarDesdeArchivo("publicaciones.txt");

        // Mostrar las publicaciones cargadas desde el archivo
        std::cout << "\nPublicaciones cargadas desde el archivo:\n";
        gestor.mostrarPublicaciones();

    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error de archivo: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Se produjo un error desconocido." << std::endl;
    }

    return 0;
}
