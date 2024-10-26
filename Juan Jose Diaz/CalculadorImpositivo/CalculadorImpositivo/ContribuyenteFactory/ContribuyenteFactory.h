#ifndef CONTRIBUYENTEFACTORY_H
#define CONTRIBUYENTEFACTORY_H

#include "../Contribuyente/Contribuyente.h"
using namespace std;

enum class CategoriaEnum {
    Limitado,
    Completo,
    Extendido
};

class ContribuyenteFactory {
    public:
        static Contribuyente* crear(const string& nombre, CategoriaEnum categoria);
};

#endif //CONTRIBUYENTEFACTORY_H
