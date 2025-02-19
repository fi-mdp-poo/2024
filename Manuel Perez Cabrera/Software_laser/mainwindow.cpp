#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logindialog.h"

#include "registerdialog.h"
#include "dialogagregarproducto.h"
#include "dialogeliminarproducto.h"
#include "pedidosClientes/dialogpedido.h"
#include "pedidosClientes/gestorpedidos.h"


MainWindow::MainWindow(const QString &usuario, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)  // Inicializar ui aquí
{
    usuarioActual = usuario;
    ui->setupUi(this);
    qDebug() << "Usuario logeado: " << usuario;  // Verificar el usuario

    // Obtener la ruta base de Documentos
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    // Crear la carpeta si no existe
    QDir().mkpath(carpetaDestino);

    // Definir las rutas de los archivos
    QString rutaStock = carpetaDestino + "/stock.csv";
    QString rutaPedidos = carpetaDestino + "/pedidos.csv";

    // Cargar stock y pedidos desde los archivos en la carpeta definida
    gestionStock.cargarStockDesdeArchivo(rutaStock);
    actualizarTabla();  // Muestra los datos cargados en la tabla

    gestorPedidos.cargarPedidosDesdeArchivo(rutaPedidos);
    actualizarTablaPedidos();  // Muestra los pedidos en la tabla
}


MainWindow::~MainWindow()
{
    // Eliminar explícitamente los items de la tabla de pedidos
    int rowCountPedidos = ui->tableWidgetPedidos->rowCount();
    for (int i = 0; i < rowCountPedidos; ++i) {
        for (int j = 0; j < ui->tableWidgetPedidos->columnCount(); ++j) {
            QTableWidgetItem* item = ui->tableWidgetPedidos->item(i, j);
            if (item) {
                delete item;  // Liberar la memoria del item
            }
        }
    }

    // Eliminar explícitamente los items de la tabla de productos
    int rowCountProductos = ui->tableWidget->rowCount();
    for (int i = 0; i < rowCountProductos; ++i) {
        for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if (item) {
                delete item;  // Liberar la memoria del item
            }
        }
    }

    delete ui;  // Eliminar el objeto de la UI
}



/******************************/
void MainWindow::setUsuarioActual(const QString &usuario) {
    usuarioActual = usuario;
}

QString MainWindow::getUsuarioActual() const {
    return usuarioActual;
}
/*
void MainWindow::actualizarTabla() {
    ui->tableWidget->clear();  // Limpiar la tabla

    QList<Producto> productos = gestionStock.obtenerProductos();
    ui->tableWidget->setRowCount(productos.size());  // Establecer el número de filas

    for (int i = 0; i < productos.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(productos[i].getNombre()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(productos[i].getCantidad())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(productos[i].getPrecio())));
    }
}
*/
void MainWindow::actualizarTabla() {
    ui->tableWidget->clearContents();  // Solo limpia los datos, sin borrar los encabezados
    ui->tableWidget->setRowCount(gestionStock.obtenerProductos().size());  // Establecer filas

    // Restablecer los encabezados de las columnas
    QStringList headers = {"Producto", "Cantidad", "Precio"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    QList<Producto*> productos = gestionStock.obtenerProductos();  // Obtener punteros a productos
    for (int i = 0; i < productos.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(productos[i]->getNombre())); // Acceder con "->"
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(productos[i]->getCantidad()))); // Acceder con "->"
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(productos[i]->getPrecio()))); // Acceder con "->"
    }
}


void MainWindow::actualizarTablaPedidos()
{
    // Limpiar la tabla antes de actualizar
    ui->tableWidgetPedidos->clearContents();
    ui->tableWidgetPedidos->setRowCount(0);

    // Obtener los pedidos desde el gestor (ahora QList<Pedidos*>)
    QList<Pedidos*> pedidos = gestorPedidos.obtenerPedidos();

    // Configurar la tabla con el número de filas necesarias
    ui->tableWidgetPedidos->setRowCount(pedidos.size());

    for (int i = 0; i < pedidos.size(); ++i) {
        Pedidos* pedido = pedidos[i];

        // Crear celdas para cada columna
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(pedido->getId()));
        QTableWidgetItem *materialItem = new QTableWidgetItem(pedido->getMaterial());
        QTableWidgetItem *cantidadItem = new QTableWidgetItem(QString::number(pedido->getCantidadMaterial()));
        QTableWidgetItem *costoItem = new QTableWidgetItem(QString::number(pedido->getCostoMaterial(), 'f', 2));
        QTableWidgetItem *gananciaItem = new QTableWidgetItem(QString::number(pedido->getGanancia(), 'f', 2));

        // Verificar si es un pedido especial
        PedidoEspecial* pedidoEspecial = dynamic_cast<PedidoEspecial*>(pedido);
        if (pedidoEspecial) {
            QColor colorEspecial(255, 223, 186); // Un color anaranjado suave
            idItem->setBackground(QBrush(colorEspecial));
            materialItem->setBackground(QBrush(colorEspecial));
            cantidadItem->setBackground(QBrush(colorEspecial));
            costoItem->setBackground(QBrush(colorEspecial));
            gananciaItem->setBackground(QBrush(colorEspecial));
        }

        // Agregar elementos a la tabla
        ui->tableWidgetPedidos->setItem(i, 0, idItem);
        ui->tableWidgetPedidos->setItem(i, 1, materialItem);
        ui->tableWidgetPedidos->setItem(i, 2, cantidadItem);
        ui->tableWidgetPedidos->setItem(i, 3, costoItem);
        ui->tableWidgetPedidos->setItem(i, 4, gananciaItem);
    }
}


/******************************/

void MainWindow::on_actionRegister_triggered()
{
    // Verificar si el usuario logueado es el administrador
    if (usuarioActual == "admin") {
        RegisterDialog registerDialog(this);  // Crear la instancia de RegisterDialog
        if (registerDialog.exec() == QDialog::Accepted) {  // Si el registro fue exitoso
            QMessageBox::information(this, "Registro", "Usuario registrado correctamente.");
        }
    } else {
        // Mostrar un mensaje si el usuario no es administrador
        QMessageBox::warning(this, "Acceso Denegado", "Solo el administrador puede registrar nuevos usuarios.");
    }
}


void MainWindow::on_actionLogOut_triggered()
{
    // Cerrar la ventana principal
    this->close();
    delete this;

    // Crear una nueva instancia de logindialog
    logindialog login;

    // Ejecutar el diálogo y verificar si el login fue exitoso
    if (login.exec() == QDialog::Accepted) {
        QString usuario = login.getUsuarioActual();  // Obtener el usuario del login
        MainWindow *w = new MainWindow(usuario);  // Pasar usuario a MainWindow
        w->show();
    }
}

/*******  AGREGAR PRODUCTOS *******/



void MainWindow::on_actionAgregar_Producto_triggered()
{
    DialogAgregarProducto dialog(this);

    if (dialog.exec() == QDialog::Accepted) {  // Si el usuario hace clic en Aceptar
        QString nombre = dialog.getNombre();
        int cantidad = dialog.getCantidad();
        double precio = dialog.getPrecio();

        // Crear un nuevo producto con puntero
        Producto* nuevoProducto = new Producto(nombre, cantidad, precio);

        // Agregar el puntero a la lista de productos
        gestionStock.agregarProducto(nuevoProducto);

        // Obtener la ruta de Documentos y la carpeta donde se guardará el archivo
        QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

        // Crear la carpeta si no existe
        QDir().mkpath(carpetaDestino);

        // Ruta del archivo de stock
        QString rutaArchivoStock = carpetaDestino + "/stock.csv";

        // Guardar el stock actualizado en el archivo
        gestionStock.guardarStockEnArchivo(rutaArchivoStock);

        // Refrescar la tabla
        actualizarTabla();
    }
}



///ELIMINA UN PRODUCTO DE LA TABLA Y LO CARGA EN UN CSV
/// \brief MainWindow::on_actionEliminar_Producto_triggered
/// TO DO : actualizar el path para hacer independiente el archivo de la pc
void MainWindow::on_actionEliminar_Producto_triggered()
{
    DialogEliminarProducto dialog(this);
    if (dialog.exec() == QDialog::Accepted) {  // Si el usuario presiona "Aceptar"
        QString nombre = dialog.getNombreProducto();
        if (!nombre.isEmpty()) {
            gestionStock.eliminarProducto(nombre);

            // Obtener la ruta base de Documentos
            QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

            // Crear la carpeta si no existe
            QDir().mkpath(carpetaDestino);

            // Definir la ruta del archivo de stock
            QString rutaStock = carpetaDestino + "/stock.csv";

            // Guardar el stock actualizado en el archivo
            gestionStock.guardarStockEnArchivo(rutaStock);

            actualizarTabla();
        } else {
            QMessageBox::warning(this, "Error", "Debe ingresar un nombre válido.");
        }
    }
}


void MainWindow::on_actionGestionar_Clientes_triggered()
{
    DialogClientes dialog(gestorClientes, this);
    dialog.exec();  // Muestra la ventana de clientes

}

void MainWindow::on_actionAgregar_Pedido_triggered()
{
    DialogPedido dialogPedidos(this);

    if (dialogPedidos.exec() == QDialog::Accepted) {
        static int nextId = 1;

        Pedidos* nuevoPedido = nullptr;

        if (dialogPedidos.esPedidoEspecial()) {
            nuevoPedido = new PedidoEspecial(nextId++,
                                             dialogPedidos.getMaterial(),
                                             dialogPedidos.getCantidadMaterial(),
                                             dialogPedidos.getCostoMaterial(),
                                             dialogPedidos.getGanancia(),
                                             dialogPedidos.getDescuento());
        } else {
            nuevoPedido = new PedidoNormal(nextId++,  // Aquí se usa PedidoNormal en lugar de Pedidos
                                           dialogPedidos.getMaterial(),
                                           dialogPedidos.getCantidadMaterial(),
                                           dialogPedidos.getCostoMaterial(),
                                           dialogPedidos.getGanancia());
        }

        gestorPedidos.agregarPedido(nuevoPedido);
        gestorPedidos.guardarPedidosEnArchivo();
        gestorPedidos.guardarPedidosEnHistorial();
        actualizarTablaPedidos();

        qDebug() << "Pedido agregado con éxito: " << nuevoPedido->obtenerDescripcion();
    }
}



