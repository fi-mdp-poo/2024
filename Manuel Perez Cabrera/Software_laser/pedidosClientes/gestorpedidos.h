#ifndef GESTORPEDIDOS_H
#define GESTORPEDIDOS_H

#include <QList>
#include <QString>
#include "pedidos.h"  // Aquí incluiríamos la clase Pedido que definiremos más tarde
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "pedidoespecial.h"
#include "pedidonormal.h"
//#include <QCoreApplication> //esta no
#include <QStandardPaths>
#include <QDir>

class GestorPedidos
{
public:
    GestorPedidos(); // Constructor
    ~GestorPedidos(); // Destructor
    void agregarPedido(Pedidos* pedido);
    void eliminarPedido(int idPedido);  // Eliminar un pedido por su ID
    QList<Pedidos*> obtenerPedidos() const;
    void guardarPedidosEnArchivo();    // Guardar todos los pedidos en un archivo
    void guardarPedidosEnHistorial();
    void cargarPedidosDesdeArchivo(const QString &nombreArchivo);  // Cargar los pedidos desde un archivo

private:
    QList<Pedidos*> listaPedidos; // Lista donde se guardan los punteros a pedidos
    QString archivoPedidos;      // Ruta del archivo donde se guardarán los pedidos
};

#endif // GESTORPEDIDOS_H
