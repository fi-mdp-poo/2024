#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente {
private:
    QString nombre;
    QString apellido;
    QString telefono;
    QString email;
    QString direccion;

public:
    Cliente(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email,const QString &direccion);
    QString getNombre() const;
    QString getApellido() const;
    QString getTelefono() const;
    QString getEmail() const;
    QString getDireccion() const;
};

#endif // CLIENTE_H
