#include "gestorclientes.h"


GestorClientes::GestorClientes()
{
    // Obtener la ruta base de Documentos
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    // Crear la carpeta si no existe
    QDir().mkpath(carpetaDestino);

    // Definir la ruta del archivo de clientes
    archivoClientes = carpetaDestino + "/clientes.csv";

    cargarClientesDesdeArchivo();
}

GestorClientes::~GestorClientes() {
    // Liberar memoria de los punteros
    qDeleteAll(listaClientes);
}

void GestorClientes::agregarCliente(Cliente *cliente) {
    listaClientes.append(cliente);
    guardarClientesEnArchivo();
}

void GestorClientes::eliminarCliente(const QString &telefono) {
    for (int i = 0; i < listaClientes.size(); ++i) {
        if (listaClientes[i]->getTelefono() == telefono) {
            delete listaClientes.takeAt(i);  // Eliminar y liberar memoria
            guardarClientesEnArchivo();
            return;
        }
    }
}

QList<Cliente*> GestorClientes::obtenerClientes() const {
    return listaClientes;
}

void GestorClientes::guardarClientesEnArchivo() {
    QFile file(archivoClientes);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para escribir.";
        return;
    }

    QTextStream out(&file);
    for (const Cliente* cliente : listaClientes) {
        out << cliente->getNombre() << ","
            << cliente->getApellido() << ","
            << cliente->getTelefono() << ","
            << cliente->getEmail() << ","
            << cliente->getDireccion() << "\n";
    }

    file.close();
}

void GestorClientes::cargarClientesDesdeArchivo() {
    QFile file(archivoClientes);
    if (!file.exists()) {
        qWarning() << "El archivo no existe, creando uno nuevo.";
        guardarClientesEnArchivo();  // Crea el archivo si no existe
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para leer.";
        return;
    }

    listaClientes.clear();  // Limpiar la lista antes de cargar
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split(",");

        if (datos.size() == 5) {
            listaClientes.append(new Cliente(datos[0], datos[1], datos[2], datos[3], datos[4]));  // Crear puntero
        } else {
            qWarning() << "Datos incorrectos en el archivo, línea ignorada:" << linea;
        }
    }

    file.close();
    qDebug() << "Clientes cargados:" << listaClientes.size();
}
