#include "Persistencia.h"
#include "Libro.h"
#include "Revista.h"
#include "Periodico.h"
#include <fstream>
#include <sstream>

void Persistencia::guardar_en_texto(const std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo) {
    std::ofstream archivo(nombre_archivo);
    for (const auto& pub : publicaciones) {
        archivo << pub->serializar() << "\n";
    }
}

void Persistencia::cargar_desde_texto(std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string tipo, titulo, autor, anio, extra;
        std::getline(iss, tipo, ',');
        std::getline(iss, titulo, ',');
        std::getline(iss, autor, ',');
        std::getline(iss, anio, ',');
        std::getline(iss, extra, ',');

        if (tipo == "Libro") {
            publicaciones.push_back(new Libro(titulo, autor, std::stoi(anio), extra));
        } else if (tipo == "Revista") {
            publicaciones.push_back(new Revista(titulo, autor, std::stoi(anio), std::stoi(extra)));
        } else if (tipo == "Periodico") {
            publicaciones.push_back(new Periodico(titulo, autor, std::stoi(anio), extra));
        }
    }
}

void Persistencia::guardar_en_binario(const std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo) {
    std::ofstream archivo(nombre_archivo, std::ios::binary);
    for (const auto& pub : publicaciones) {
        std::string serializado = pub->serializar() + "\n";
        archivo.write(serializado.c_str(), serializado.size());
    }
}

void Persistencia::cargar_desde_binario(std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo) {
    std::ifstream archivo(nombre_archivo, std::ios::binary);
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string tipo, titulo, autor, anio, extra;
        std::getline(iss, tipo, ',');
        std::getline(iss, titulo, ',');
        std::getline(iss, autor, ',');
        std::getline(iss, anio, ',');
        std::getline(iss, extra, ',');

        if (tipo == "Libro") {
            publicaciones.push_back(new Libro(titulo, autor, std::stoi(anio), extra));
        } else if (tipo == "Revista") {
            publicaciones.push_back(new Revista(titulo, autor, std::stoi(anio), std::stoi(extra)));
        } else if (tipo == "Periodico") {
            publicaciones.push_back(new Periodico(titulo, autor, std::stoi(anio), extra));
        }
    }
}

