#include "GestionStock.h"

GestionStock::GestionStock()
{
    // Aquí puedes agregar cualquier inicialización adicional si lo deseas
    qDebug() << "GestionStock: Constructor por defecto llamado.";

    // Si quieres inicializar algo en particular, por ejemplo:
    // productos.clear();  // Asegura que no haya productos previamente cargados
}

GestionStock::~GestionStock() {
    // Eliminar explícitamente cada producto en la lista
    for (Producto* producto : productos) {
        delete producto;  // Liberar la memoria de cada objeto Producto
    }
    productos.clear();  // Limpiar la lista después de eliminar los productos
}
void GestionStock::agregarProducto(Producto* producto) {
    productos.append(producto); // Añadir el puntero a la lista
}

  // Necesario para mostrar el cuadro de mensaje

void GestionStock::eliminarProducto(const QString &nombre) {
    bool encontrado = false;
    for (int i = 0; i < productos.size(); ++i) {
        if (productos[i]->getNombre() == nombre) { // Usar el operador "->" para acceder a los miembros
            delete productos[i];  // Eliminar el puntero
            productos.removeAt(i);
            encontrado = true;
            break;
        }
    }

    // Si no se encontró el producto
    if (!encontrado) {
        // Mostrar mensaje de error
        QMessageBox::warning(nullptr, "Error", "Nombre de producto incorrecto", QMessageBox::Ok);
    }
}

void GestionStock::editarProducto(const QString &nombre, int nuevaCantidad, double nuevoPrecio) {
    for (int i = 0; i < productos.size(); ++i) {
        if (productos[i]->getNombre() == nombre) {
            productos[i]->setCantidad(nuevaCantidad);
            productos[i]->setPrecio(nuevoPrecio);
            return;
        }
    }
}

QList<Producto*> GestionStock::obtenerProductos() const {
    return productos;
}

void GestionStock::cargarStockDesdeArchivo(const QString &nombreArchivo) {
    QFile file(nombreArchivo);

    // Si el archivo no existe, lo creamos vacío
    if (!file.exists()) {
        qWarning() << "El archivo no existe. Creando uno nuevo...";
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "No se pudo crear el archivo.";
            return;
        }
        file.close(); // Cerramos el archivo vacío
    }

    // Ahora lo abrimos para lectura
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para leer.";
        return;
    }

    productos.clear(); // Limpiar la lista antes de cargar nuevos datos

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split(",");

        if (datos.size() == 3) {
            QString nombre = datos[0];
            int cantidad = datos[1].toInt();
            double precio = datos[2].toDouble();

            productos.append(new Producto(nombre, cantidad, precio)); // Crear un puntero con "new"
        }
    }

    file.close();
}

void GestionStock::guardarStockEnArchivo(const QString &nombreArchivo) {
    QFile file(nombreArchivo);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para escribir.";
        return;
    }

    QTextStream out(&file);
    for (Producto* producto : productos) {
        out << producto->getNombre() << "," // Usar "->" para acceder a los miembros
            << producto->getCantidad() << ","
            << producto->getPrecio() << "\n";
    }

    file.close();
}
