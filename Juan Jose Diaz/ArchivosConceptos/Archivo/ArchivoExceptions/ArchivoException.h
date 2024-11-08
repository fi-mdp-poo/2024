#ifndef ARCHIVOEXCEPTION_H
#define ARCHIVOEXCEPTION_H

class ArchivoException : public runtime_error {
    public:
        explicit ArchivoException(const string& mensaje) : runtime_error(mensaje) {
        }
};

#endif //ARCHIVOEXCEPTION_H
