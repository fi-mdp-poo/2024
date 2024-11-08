#ifndef ARCHIVOLECTURAEXCEPTION_H
#define ARCHIVOLECTURAEXCEPTION_H

#include "ArchivoException.h"

class ArchivoLecturaException final : public ArchivoException {
    public:
        explicit ArchivoLecturaException(const string& mensaje) : ArchivoException("Error de lectura: " + mensaje) {
        }
};

#endif //ARCHIVOLECTURAEXCEPTION_H
