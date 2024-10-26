#include "ContribuyenteFactory.h"

Contribuyente* ContribuyenteFactory::crear(const string& nombre, const CategoriaEnum categoria) {
    switch (categoria) {
        case CategoriaEnum::Limitado:
            return new Limitado(nombre);
        case CategoriaEnum::Completo:
            return new Completo(nombre);
        case CategoriaEnum::Extendido:
            return new Extendido(nombre);
        default:
            return nullptr;
    }
}
