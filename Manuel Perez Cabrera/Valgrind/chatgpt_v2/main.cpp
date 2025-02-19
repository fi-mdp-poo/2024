#include "Libro.h"
#include "Revista.h"
#include "Periodico.h"
#include "Persistencia.h"
#include <iostream>
#include <vector>

int main() {
    // Crear vector de Publicacion*
    std::vector<Publicacion*> publicaciones;

    // Documentación inicial
    std::cout << "=== Sistema de Gestión de Biblioteca ===" << std::endl;

    // Crear y agregar publicaciones
    std::cout << "Creando publicaciones..." << std::endl;
    publicaciones.push_back(new Libro("C++ Primer", "Lippman", 2013, "Educación"));
    publicaciones.push_back(new Revista("National Geographic", "Varios", 2021, 100));
    publicaciones.push_back(new Periodico("El País", "Editorial", 2024, "2024-11-27"));

    // Mostrar publicaciones
    std::cout << "Mostrando publicaciones creadas:" << std::endl;
    for (const auto& pub : publicaciones) {
        pub->mostrar_detalle();
    }

    // Guardar en archivos
    std::cout << "Guardando publicaciones en archivos..." << std::endl;
    Persistencia::guardar_en_texto(publicaciones, "publicaciones.txt");
    Persistencia::guardar_en_binario(publicaciones, "publicaciones.dat");

    // Limpiar el vector para cargar desde persistencia
    for (auto& pub : publicaciones) {
        delete pub; // Liberar memoria manualmente
    }
    publicaciones.clear();

    // Cargar desde archivo de texto
    std::cout << "Cargando publicaciones desde archivo de texto..." << std::endl;
    Persistencia::cargar_desde_texto(publicaciones, "publicaciones.txt");
    std::cout << "Publicaciones cargadas desde texto:" << std::endl;
    for (const auto& pub : publicaciones) {
        pub->mostrar_detalle();
    }

    // Cargar desde archivo binario
    std::cout << "Limpiando publicaciones y cargando desde archivo binario..." << std::endl;
    for (auto& pub : publicaciones) {
        delete pub; // Liberar memoria manualmente
    }
    publicaciones.clear();
    Persistencia::cargar_desde_binario(publicaciones, "publicaciones.dat");

    std::cout << "Publicaciones cargadas desde binario:" << std::endl;
    for (const auto& pub : publicaciones) {
        pub->mostrar_detalle();
    }

    // Modificación de una publicación
    std::cout << "Modificando título de la primera publicación..." << std::endl;
    if (!publicaciones.empty()) {
        publicaciones[0]->establecer_titulo("C++ Primer Edición Actualizada");
        publicaciones[0]->mostrar_detalle();
    }

    // Eliminación de publicaciones
    std::cout << "Eliminando todas las publicaciones..." << std::endl;
    for (auto& pub : publicaciones) {
        delete pub; // Liberar memoria manualmente
    }
    publicaciones.clear();
    std::cout << "Todas las publicaciones han sido eliminadas." << std::endl;

    std::cout << "=== Fin del programa ===" << std::endl;

    return 0;
}
