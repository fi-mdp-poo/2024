#include "gestorpedidos.h"

GestorPedidos::GestorPedidos() {
    // Obtener la ruta de la carpeta "Documentos" del usuario
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    // Verificar si la carpeta existe, si no, crearla
    QDir dir(carpetaDestino);
    if (!dir.exists()) {
        dir.mkpath(".");  // Crea la carpeta si no existe
    }

    // Ruta final del archivo pedidos.csv dentro de la carpeta
    archivoPedidos = carpetaDestino + "/pedidos.csv";
}

GestorPedidos::~GestorPedidos() {
    // Liberamos los recursos de los objetos Pedidos al destruir el GestorPedidos
    qDeleteAll(listaPedidos); // Esto eliminará todos los objetos Pedidos de la lista
}

void GestorPedidos::agregarPedido(Pedidos* pedido) {
    listaPedidos.append(pedido);
}

void GestorPedidos::eliminarPedido(int idPedido) {
    for (int i = 0; i < listaPedidos.size(); ++i) {
        if (listaPedidos[i]->getId() == idPedido) {
            delete listaPedidos.takeAt(i);  // Eliminar el pedido y liberar la memoria
            return;
        }
    }
}

QList<Pedidos*> GestorPedidos::obtenerPedidos() const {
    return listaPedidos;
}

void GestorPedidos::guardarPedidosEnArchivo() {
    QFile file(archivoPedidos);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para escribir.";
        return;
    }

    QTextStream out(&file);
    for (const Pedidos* pedido : listaPedidos) {
        // Escribir los datos en un formato CSV, separados por comas
        out << pedido->getId() << ","
            << pedido->getMaterial() << ","
            << pedido->getCantidadMaterial() << ","
            << pedido->getCostoMaterial() << ","
            << pedido->getGanancia();

        // Si es un PedidoEspecial, incluir el descuento
        if (dynamic_cast<const PedidoEspecial*>(pedido)) {
            const PedidoEspecial* pedidoEspecial = dynamic_cast<const PedidoEspecial*>(pedido);
            out << ",especial," << pedidoEspecial->getDescuento();
        } else {
            out << ",normal";
        }

        out << "\n";  // Nueva línea por cada pedido
    }

    file.close();
}

void GestorPedidos::cargarPedidosDesdeArchivo(const QString &nombreArchivo) {
    QFile file(nombreArchivo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para leer.";
        return;
    }

    listaPedidos.clear();  // Limpiar la lista antes de cargar nuevos datos

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split(",");

        if (datos.size() >= 5) {
            int id = datos[0].toInt();
            QString material = datos[1];
            int cantidad = datos[2].toInt();
            double costo = datos[3].toDouble();
            double ganancia = datos[4].toDouble();

            // Supongamos que el último campo indica si es un pedido especial (por ejemplo, "especial" o "normal")
            bool esEspecial = datos.size() > 5 && datos[5] == "especial";

            Pedidos* nuevoPedido = nullptr;
            if (esEspecial) {
                double descuento = datos.size() > 6 ? datos[6].toDouble() : 0.0;
                nuevoPedido = new PedidoEspecial(id, material, cantidad, costo, ganancia, descuento);
            } else {
                nuevoPedido = new PedidoNormal(id, material, cantidad, costo, ganancia);
            }

            listaPedidos.append(nuevoPedido);
        }
    }

    file.close();
}

#include <QDateTime> // Para obtener la fecha y hora actual

void GestorPedidos::guardarPedidosEnHistorial() {

    // Obtener la ruta de la carpeta "Documentos" del usuario
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    // Verificar si la carpeta existe, si no, crearla
    QDir dir(carpetaDestino);
    if (!dir.exists()) {
        dir.mkpath(".");  // Crea la carpeta si no existe
    }

    // Ruta final del archivo dentro de la carpeta
    QString rutaArchivo = carpetaDestino + "/historial_pedidos.txt";
    QFile file(rutaArchivo);
    // Intentamos abrir el archivo en modo Append para agregar solo el nuevo pedido
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo de historial para escribir.";
        return;
    }

    // Creamos un QTextStream para escribir en el archivo
    QTextStream out(&file);

    // Obtener la fecha y hora actual
    QString fechaHora = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // Escribimos el separador y la fecha del pedido
    out << "-------------------------------------\n";
    out << "Fecha y hora: " << fechaHora << "\n";

    // Escribimos solo el último pedido (el último en la lista)
    if (!listaPedidos.isEmpty()) {
        const Pedidos* ultimoPedido = listaPedidos.last();
        out << "ID: " << ultimoPedido->getId() << "\n"
            << "Material: " << ultimoPedido->getMaterial() << "\n"
            << "Cantidad del material: " << ultimoPedido->getCantidadMaterial() << "\n"
            << "Costo del material: " << ultimoPedido->getCostoMaterial() << "\n"
            << "Ganancia: " << ultimoPedido->getGanancia() << "\n";

        // Verificar si es un PedidoEspecial
        const PedidoEspecial* pedidoEspecial = dynamic_cast<const PedidoEspecial*>(ultimoPedido);
        if (pedidoEspecial) {
            out << "Tipo: Pedido Especial\n";
            out << "Descuento aplicado: " << pedidoEspecial->getDescuento() << "\n";
        } else {
            out << "Tipo: Pedido Normal\n";
        }
    }

    // Cerramos el archivo
    file.close();
    qDebug() <<  rutaArchivo ;
}

