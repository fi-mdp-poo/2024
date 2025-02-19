#include "producto.h"

Producto::Producto(const QString &nombre, int cantidad, double precio)
    : nombre(nombre), cantidad(cantidad), precio(precio) {}

QString Producto::getNombre() const {
    return nombre;
}

int Producto::getCantidad() const {
    return cantidad;
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}
