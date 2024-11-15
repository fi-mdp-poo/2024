#ifndef ARCHIVOAPERTURAEXCEPTION_H
#define ARCHIVOAPERTURAEXCEPTION_H

#include "ArchivoException.h"

class ArchivoAperturaException final : public ArchivoException {
    public:
        explicit ArchivoAperturaException(const string& nombreArchivo) : ArchivoException(
            "Error al abrir el archivo " + nombreArchivo) {
        }
};

#endif //ARCHIVOAPERTURAEXCEPTION_H
