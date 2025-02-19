#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto {
public:
    Producto(const QString &nombre, int cantidad, double precio);
    QString getNombre() const;
    int getCantidad() const;
    double getPrecio() const;
    void setCantidad(int cantidad);
    void setPrecio(double precio);

private:
    QString nombre;
    int cantidad;
    double precio;
};

#endif // PRODUCTO_H
