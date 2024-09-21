#include <iostream>
#include <fstream>
#include <cstring>

struct Persona {
    int id;
    char* nombre;
};

int main() {
    // Escribir datos en un archivo binario
    std::ofstream archivoSalida("personas.bin", std::ios::binary);
    if (archivoSalida.is_open()) {
        Persona personas[2];

        personas[0].id = 1;
        personas[0].nombre = new char[50];
        std::strcpy(personas[0].nombre, "Juan");

        personas[1].id = 2;
        personas[1].nombre = new char[50];
        std::strcpy(personas[1].nombre, "Maria");

        for (int i = 0; i < 2; i++) {
            int longitudNombre = std::strlen(personas[i].nombre);
            archivoSalida.write(reinterpret_cast<char*>(&longitudNombre), sizeof(longitudNombre));
            archivoSalida.write(personas[i].nombre, longitudNombre);
            archivoSalida.write((char*)&personas[i].id, sizeof(int));
        }

        archivoSalida.close();

        // Liberar la memoria asignada para los nombres
        delete[] personas[0].nombre;
        delete[] personas[1].nombre;
    } else {
        std::cerr << "No se pudo abrir el archivo binario para escritura." << std::endl;
        return 1;
    }

    // Leer datos desde un archivo binario
    std::ifstream archivoEntrada("personas.bin", std::ios::binary);
    if (archivoEntrada.is_open()) {
        Persona personas[2];

        for (int i = 0; i < 2; i++) {
            int longitudNombre;
            archivoEntrada.read(reinterpret_cast<char*>(&longitudNombre), sizeof(longitudNombre));
            personas[i].nombre = new char[longitudNombre + 1];
            archivoEntrada.read(personas[i].nombre, longitudNombre);
            personas[i].nombre[longitudNombre] = '\0'; // Agregar el nulo al final
            archivoEntrada.read(reinterpret_cast<char*>(&personas[i].id), sizeof(personas[i].id));
        }

        archivoEntrada.close();

        for (int i = 0; i < 2; i++) {
            std::cout << "ID: " << personas[i].id << std::endl;
            std::cout << "Nombre: " << personas[i].nombre << std::endl;
        }

        // Liberar la memoria asignada para los nombres
        for (int i = 0; i < 2; i++) {
            delete[] personas[i].nombre;
        }
    } else {
        std::cerr << "No se pudo abrir el archivo binario para lectura." << std::endl;
        return 1;
    }

    return 0;
}
