#include "Persona.h"

Persona::Persona() = default;

Persona::Persona(const string& nombre, const string& direccion, const string& telefono) {
    _nombre = nombre;
    _direccion = direccion;
    _telefono = telefono;
}

ostream& operator<<(ostream& os, const Persona& p) {
    // Con el siguiente formato se va a guardar el registro en el archivo
    os << p._nombre << "," << p._direccion << "," << p._telefono;
    return os;
}

istream& operator>>(istream& is, Persona& p) {
    getline(is, p._nombre, ','); // Lee hasta la primera coma y asigna el valor al atributo `nombre`
    getline(is, p._direccion, ','); // Lee hasta la segunda coma y asigna el valor al atributo `direccion`
    getline(is, p._telefono); // Lee el resto de la línea y asigna el valor al atributo `telefono`
    return is; // Devuelve el flujo de entrada para permitir encadenamiento
}