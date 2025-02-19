#ifndef GESTIONSTOCK_H
#define GESTIONSTOCK_H

#include <QList>
#include "producto.h"
#include <QFile>
#include <qdebug.h>
#include <QMessageBox>

class GestionStock {
public:

    GestionStock();
    ~GestionStock();  // Añadimos el destructor
    void agregarProducto(Producto* producto); // Ahora acepta punteros
    void eliminarProducto(const QString &nombre);
    void editarProducto(const QString &nombre, int nuevaCantidad, double nuevoPrecio);
    QList<Producto*> obtenerProductos() const; // Ahora devuelve una lista de punteros
    void guardarStockEnArchivo(const QString &nombreArchivo);
    void cargarStockDesdeArchivo(const QString &nombreArchivo);

private:
    QList<Producto*> productos;  // Contenedor de punteros a productos
};

#endif // GESTIONSTOCK_H

