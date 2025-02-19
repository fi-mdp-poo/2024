#ifndef GESTORCLIENTES_H
#define GESTORCLIENTES_H

#include "cliente.h"
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QStandardPaths>
#include <QDir>

class GestorClientes {
private:
    QList<Cliente*> listaClientes;
    QString archivoClientes;  // Archivo donde se guardarán los clientes

public:
    GestorClientes();
    ~GestorClientes();  // Destructor para liberar memoria de los punteros
    void agregarCliente(Cliente *cliente);  // Cambiar para recibir punteros
    void eliminarCliente(const QString &telefono);
    QList<Cliente*> obtenerClientes() const;  // Cambiar el retorno a punteros
    void guardarClientesEnArchivo();
    void cargarClientesDesdeArchivo();
};

#endif // GESTORCLIENTES_H

