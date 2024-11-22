#include <iostream>
#include <vector>
#include "Publicacion.h"
#include "GestionPublicaciones.h"
#include "Archivo.h"

using namespace std;

int main() {
    // Crear instancias de publicaciones
    Libro libro("C++ para principiantes", "Juan Perez", 2021, "Educacion");
    Revista revista("Revista de Ciencia", "Ana Gomez", 2023, 5);
    Periodico periodico("El Mundo", "Carlos Sanchez", 2023, "Madrid");

    // Crear el gestor de publicaciones
    GestionPublicaciones<Publicacion> gestion;

    // Agregar publicaciones
    gestion.agregar(libro);
    gestion.agregar(revista);
    gestion.agregar(periodico);

    // Imprimir todas las publicaciones
    gestion.imprimirTodo();

    // Buscar una publicación
    Publicacion* p = gestion.buscarPorTitulo("C++ para principiantes");
    if (p) {
        cout << "Encontrada: ";
        p->imprimir();
    }

    // Eliminar una publicación
    if (gestion.eliminarPorTitulo("El Mundo")) {
        cout << "Publicacion eliminada." << endl;
    }

    // Modificar una publicación
    Libro nuevoLibro("C++ avanzado", "Juan Perez", 2022, "Tecnologia");
    if (gestion.modificarPorTitulo("C++ para principiantes", nuevoLibro)) {
        cout << "Publicacion modificada." << endl;
    }

    // Imprimir después de modificar
    gestion.imprimirTodo();

    // Guardar en archivo de texto
    vector<Libro> libros = {libro, nuevoLibro};
    guardarEnArchivoTexto(libros, "libros.txt");

    return 0;
}

