#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "Publicacion.h"
#include <vector>
#include <memory>
#include <string>

class Persistencia {
public:
//    static void guardar_en_texto(const std::vector<std::shared_ptr<Publicacion>>& publicaciones, const std::string& nombre_archivo);
//    static void cargar_desde_texto(std::vector<std::shared_ptr<Publicacion>>& publicaciones, const std::string& nombre_archivo);
//
//    static void guardar_en_binario(const std::vector<std::shared_ptr<Publicacion>>& publicaciones, const std::string& nombre_archivo);
//    static void cargar_desde_binario(std::vector<std::shared_ptr<Publicacion>>& publicaciones, const std::string& nombre_archivo);

static void guardar_en_texto(const std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo);
static void cargar_desde_texto(std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo);

static void guardar_en_binario(const std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo);
static void cargar_desde_binario(std::vector<Publicacion*>& publicaciones, const std::string& nombre_archivo);

};

#endif // PERSISTENCIA_H
