#include "cliente.h"

Cliente::Cliente(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email, const QString &direccion)
    : nombre(nombre), apellido(apellido), telefono(telefono), email(email), direccion(direccion) {}

QString Cliente::getNombre() const
{
    return nombre;
}
QString Cliente::getApellido() const
{
    return apellido;
}
QString Cliente::getTelefono() const
{
    return telefono;
}
QString Cliente::getEmail() const
{
    return email;
}
QString Cliente::getDireccion() const
{
    return direccion;
}
